/*---------------------------------------------------------------------------*\
Copyright (C) 2018 by the LUEUR authors

License
This project is licensed under The 3-Clause BSD License. For further information
look for license file include with distribution.

\*---------------------------------------------------------------------------*/

#include "powerControlD.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace emcModels
{
    defineTypeNameAndDebug(powerD, 0);
    addToRunTimeSelectionTable(emcModel, powerD, dictionary);
};
};

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::emcModels::powerD::powerD
(
	const dictionary& electroMagnetics,
	multiSpeciesPlasmaModel& mspm,
	const volVectorField& E,
	const Time& runTime
)
:
    emcModel(electroMagnetics, mspm, E, runTime),	// modes to be considered. 
	mode_(emcModelCoeffs_.lookup("mode")),	// of course I need this in order to even read it
    initialAmplitude_(readScalar(emcModelCoeffs_.lookup("initialAmplitude"))),	// initial amplitude selected
    frequency_(readScalar(emcModelCoeffs_.lookup("frequency"))),	// frequency of the case 
    bias_(readScalar(emcModelCoeffs_.lookup("bias"))),	// bias. For this thing lets just leave it as it
    power_(readScalar(emcModelCoeffs_.lookup("power"))),	// power input into the calculation
    nCycles_(readInt(emcModelCoeffs_.lookup("controlFrequency"))),	// number of cycles to be considered in the power calculation
    dampingFactor_(readScalar(emcModelCoeffs_.lookup("dampingFactor"))),	// This is the damping calculations. 
    mf_(readScalar(emcModelCoeffs_.lookup("geometricFactor"))),	// this adjust the ratio wanted within mesh dimensions and what is desired.
	timeCounter_(0.0),	// is initially 0 but then it gets updated eventually.
	timeCount_(0.0),	// This is just for the number of periods we care about.
	curTimeIndex_(time_.timeIndex()),	// in reality this is runTime.timeIndex()
	powerLogFilePtr_(NULL),	// this is the log file for voltage.
    amplitude_(0.0),	// This is the amplitude that is going to update towards the dielectric.
    powerSum_(0.0),		// this guy is called powerSum.

    dutyCycle_(readScalar(emcModelCoeffs_.lookup("dutyCycle"))),
    voltageOperation_(emcModelCoeffs_.lookup("voltageMode")),	// this will determine whenever I want to use sinusoidal or squared function
    pulsedMode_(emcModelCoeffs_.lookup("pulsedMode")),	// this will set up the mode of operation if pulsed is true
    

    meshV_			
    (
        IOobject
        (
            "meshV",
            E_.mesh().time().timeName(),
            E_.mesh(),
            IOobject::NO_READ,
            IOobject::NO_WRITE
        ),
        E_.mesh(),
		dimensionedScalar("zero", dimensionSet(0, 0, 0, 1, 0), 0.0)
    )
{
	meshV_.internalField() = E_.mesh().V();

    if (Pstream::master())
    {
        powerLogFilePtr_ =
            new OFstream
            (fileName("power_voltage_logfile"));
        OFstream& powerLogFile = *powerLogFilePtr_;
        int width = 20;
        powerLogFile << "time";
        powerLogFile.width(width);
        powerLogFile << "power";
        powerLogFile.width(width);
        powerLogFile << "voltage";
		powerLogFile << endl;
    }
}

// * * * * * * * * * * * * * * * * Destructors * * * * * * * * * * * * * * * //

Foam::emcModels::powerD::~powerD()
{}

// * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * * //

inline Foam::scalar Foam::emcModels::powerD::powerSumMesh() const
{
    const objectRegistry& db = E_.db();
    const volVectorField& tddtE = db.lookupObject<volVectorField>("ddtE");

	volScalarField tpowerSumMesh = meshV_*((plasmaConstants::eCharge*mspm_.netChargeFlux() + plasmaConstants::epsilon0*tddtE) & E_);

    return gSum(tpowerSumMesh);
}

// this is the part I care about since we will couple this with the dielectric of choice. 

void Foam::emcModels::powerD::correct(dictionary& voltageDictD)
{
	if (mode_ == "continuousFrequencyModulated")
	{
		const scalar& tpower = powerSumMesh();

		powerSum_ += tpower;

		curTimeIndex_ = time_.timeIndex();

		if(curTimeIndex_ == 1)
		{
			amplitude_ = initialAmplitude_;
		}

		timeCount_ = nCycles_/frequency_/time_.deltaT().value();

		if(curTimeIndex_ - timeCounter_ >= timeCount_)
		{
			timeCounter_ =  curTimeIndex_;

			scalar powerSumAve_ = powerSum_*mf_/timeCount_;

			powerSum_ = 0.0;

			scalar amplitudeold_(amplitude_);

			amplitude_ = amplitudeold_*(1.0-dampingFactor_*((powerSumAve_/power_)-1.0));

			if((amplitude_/amplitudeold_) >= 1.1)
			{
				amplitude_ = 1.1*amplitudeold_;
			}
			else if((amplitude_/amplitudeold_) <= 0.9)
			{
				amplitude_ = 0.9*amplitudeold_;
			}

			if (Pstream::master())
			{
			   OFstream& powerLogFile = *powerLogFilePtr_;
			   int width = 20;
			   powerLogFile << time_.value();
			   powerLogFile.width(width);
			   powerLogFile << powerSumAve_;
			   powerLogFile.width(width);
			   powerLogFile << amplitude_;
			   powerLogFile << endl;
			}
		}


		if (voltageOperation_ == "sinusoidal")
		{
			scalar voltageValueD = amplitude_*Foam::cos(2.0*M_PI*frequency_*time_.value()) + bias_;
			voltageDictD.set("voltageD", voltageValueD);
		}
		else if (voltageOperation_ == "squared")
		{
			// Info << "Hello powerControlD?" << endl;
			scalar period = 1/frequency_;
			scalar period_duty = period*dutyCycle_/100;

			scalar n = floor((this->db().time().value())/period);

			if (pulsedMode_ == "classical")
			{
				if (this->db().time().value()<period*n+(period/2))
				{
					scalar voltageValueD = amplitude_;
					voltageDictD.set("voltageD", voltageValueD);
				}
				else if (this->db().time().value()>period*(n)+(period/2))
				{
					scalar voltageValueD = -amplitude_;
					voltageDictD.set("voltageD", voltageValueD);
				}
			}
			
			else if (pulsedMode_ == "floored")
			{
				if (this->db().time().value()<period*(n)+period_duty)
				{
					scalar voltageValueD = amplitude_;
					voltageDictD.set("voltageD", voltageValueD);
					// Info << "floor1" << endl;
				}
				else if (this->db().time().value()>period*(n)+period_duty)
				{
					scalar voltageValueD = 0;
					voltageDictD.set("voltageD", voltageValueD);
					// Info << "floor2" << endl;
				}
			}

			else if (pulsedMode_ == "negativeFloored")
			{
				if (this->db().time().value()<period*(n)+period_duty)
				{
					scalar voltageValueD = -amplitude_;
					voltageDictD.set("voltageD", voltageValueD);
				}
				else if (this->db().time().value()>period*(n)+period_duty)
				{
					scalar voltageValueD = 0;
					voltageDictD.set("voltageD", voltageValueD);
				}
			}

			else if (pulsedMode_ == "bias")
			{
				if (this->db().time().value()<period*(n)+period_duty)
				{
					scalar voltageValueD = amplitude_+bias_; 
					voltageDictD.set("voltageD", voltageValueD);
				}
				else if (this->db().time().value()>period*(n)+period_duty)
				{
					scalar voltageValueD = -amplitude_+bias_; 
					voltageDictD.set("voltageD", voltageValueD);
				}
			}

		}
	}
	
	else
	{
        FatalErrorIn("emcModels::power::correct(dictionary& voltageDictD)")
            << " incorrect mode "
            << exit(FatalError);
	}
}


bool Foam::emcModels::powerD::read(const dictionary& electroMagnetics)
{
    emcModel::read(electroMagnetics);

    emcModelCoeffs_.lookup("initialAmplitude") >> initialAmplitude_;
    emcModelCoeffs_.lookup("frequency") >> frequency_;
    emcModelCoeffs_.lookup("bias") >> bias_;
    emcModelCoeffs_.lookup("power") >> power_;
    emcModelCoeffs_.lookup("controlFrequency") >> nCycles_;
    emcModelCoeffs_.lookup("dampingFactor") >> dampingFactor_;
    emcModelCoeffs_.lookup("geometricFactor") >> mf_;

    return true;
}


// ************************************************************************* //
