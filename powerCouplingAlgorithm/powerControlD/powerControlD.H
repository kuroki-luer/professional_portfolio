/*---------------------------------------------------------------------------*\
Copyright (C) 2018 by the LUEUR authors

License
This project is licensed under The 3-Clause BSD License. For further information
look for license file include with distribution.

\*---------------------------------------------------------------------------*/

#ifndef powerControlD_H
#define powerControlD_H

#include "emcModels.H"

namespace Foam
{
namespace emcModels
{

/*---------------------------------------------------------------------------*\
                          Class power Declaration
\*---------------------------------------------------------------------------*/

class powerD
:
    public emcModel
{
    // Private data
		const word mode_;
		scalar initialAmplitude_;
		scalar frequency_;
		scalar bias_;
		scalar power_;
		int nCycles_;
		scalar dampingFactor_;
		scalar mf_;
		scalar timeCounter_;
		scalar timeCount_;
		label curTimeIndex_;

		OFstream* powerLogFilePtr_;
		scalar amplitude_;
		scalar powerSum_;

        scalar dutyCycle_;
		word voltageOperation_;
		word pulsedMode_;
        
        volScalarField meshV_;

    // Private Member Functions

        inline scalar powerSumMesh() const;

        //- Disallow copy construct
        powerD(const powerD&);

        //- Disallow default bitwise assignment
        void operator=(const powerD&);


public:

    //- Runtime type information
    TypeName("powerD");


    // Constructors

        //- Construct from components
        powerD
        (
			const dictionary& electroMagnetics,
			multiSpeciesPlasmaModel& mspm,
			const volVectorField& E,
			const Time& runTime
        );


    // Destructor

        virtual ~powerD();

    // Member Functions

        virtual void correct(dictionary& voltageDictD);

        //- Update properties from given dictionary
        virtual bool read(const dictionary& electroMagnetics);
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} 
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
