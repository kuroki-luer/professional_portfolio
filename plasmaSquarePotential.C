/*---------------------------------------------------------------------------*\
Copyright (C) 2018 by the LUEUR authors

License
This project is licensed under The 3-Clause BSD License. For further information
look for license file include with distribution.

\*---------------------------------------------------------------------------*/

#include "plasmaSquarePotential.H"
#include "addToRunTimeSelectionTable.H"
#include "fvPatchFieldMapper.H"
#include "mathematicalConstants.H"
#include "foamTime.H"
#include "volFields.H"

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //
Foam::plasmaSquarePotential::
plasmaSquarePotential
(
    const fvPatch& p,
    const DimensionedField<scalar, volMesh>& iF
)
:
    // value of the boundary condition at a particular instance 
    fixedValueFvPatchScalarField(p, iF),

    // standard definitions 
    amplitude_(p.size(), 0.0),
    mode_("classical"),
    frequency_(0.0),
    dutyCycle_(0.0),
    bias_(0.0)    
{}


Foam::plasmaSquarePotential::
plasmaSquarePotential
(
    const fvPatch& p,
    const DimensionedField<scalar, volMesh>& iF,
    const dictionary& dict
)
:
    fixedValueFvPatchScalarField(p, iF),
    amplitude_("amplitude", dict, p.size()),
    mode_(dict.lookupOrDefault<word>("mode", "classical")),
    frequency_(dict.lookupOrDefault<scalar>("frequency", 0.0)),
    dutyCycle_(dict.lookupOrDefault<scalar>("dutyCycle", 0.0)),
    bias_(dict.lookupOrDefault<scalar>("bias", 0.0))
{
    if (dict.found("value"))
    {
        fvPatchField<scalar>::operator=
        (
            scalarField("value", dict, p.size())
        );
    }
    else
    {
        fvPatchField<scalar>::operator=(patchInternalField());
    }
}

Foam::plasmaSquarePotential::
plasmaSquarePotential
(
    const plasmaSquarePotential& ptf,
    const fvPatch& p,
    const DimensionedField<scalar, volMesh>& iF,
    const fvPatchFieldMapper& mapper
)
:
    fixedValueFvPatchScalarField(ptf, p, iF, mapper),
    amplitude_(ptf.amplitude_, mapper),
    mode_(ptf.mode_),
    frequency_(ptf.frequency_),
    dutyCycle_(ptf.dutyCycle_),
    bias_(ptf.bias_)
{}


Foam::plasmaSquarePotential::
plasmaSquarePotential
(
    const plasmaSquarePotential& tppsf
)
:
    fixedValueFvPatchScalarField(tppsf),
    amplitude_(tppsf.amplitude_),
    mode_(tppsf.mode_),
    frequency_(tppsf.frequency_),
    dutyCycle_(tppsf.dutyCycle_),
    bias_(tppsf.bias_)
{}


Foam::plasmaSquarePotential::
plasmaSquarePotential
(
    const plasmaSquarePotential& tppsf,
    const DimensionedField<scalar, volMesh>& iF
)
:
    fixedValueFvPatchScalarField(tppsf, iF),
    amplitude_(tppsf.amplitude_),
    mode_(tppsf.mode_),
    frequency_(tppsf.frequency_),
    dutyCycle_(tppsf.dutyCycle_),
    bias_(tppsf.bias_)
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

void Foam::plasmaSquarePotential::autoMap
(
    const fvPatchFieldMapper& m
)
{
    fixedValueFvPatchScalarField::autoMap(m);
    amplitude_.autoMap(m);
}


void Foam::plasmaSquarePotential::rmap
(
    const fvPatchScalarField& ptf,
    const labelList& addr
)
{
    fixedValueFvPatchScalarField::rmap(ptf, addr);

    const plasmaSquarePotential& tiptf =
        refCast<const plasmaSquarePotential>(ptf);

    amplitude_.rmap(tiptf.amplitude_, addr);
}

void Foam::plasmaSquarePotential::updateCoeffs()
{
    if (updated())
    {
        return;
    }

    scalar period = 1/frequency_;
    scalar period_duty = period*dutyCycle_/100;

    scalar n = floor((this->db().time().value())/period);

    if (mode_ == "classical")
    {
        if (this->db().time().value()<period*(n)+(period/2))
        {
            operator==(amplitude_);
            Info << "before" << endl;
        }
        else if (this->db().time().value()>period*(n)+(period/2))
        {
            operator ==(-amplitude_);
            Info << "after" << endl;

        }

    }
    else if (mode_ == "floored")
    {
        if (this->db().time().value()<period*(n)+period_duty)
        {
            operator==(amplitude_);
        }
        else if (this->db().time().value()>period*(n)+period_duty)
        {
            operator==(0);
        }

    }
    else if (mode_ == "duty")
    {
        if (this->db().time().value()<period*(n)+period_duty)
        {
            operator==(amplitude_);
        }
        else if (this->db().time().value()>period*(n)+period_duty)
        {
            operator==(-amplitude_);
        }
    }
    else if (mode_ == "negativeFloored")
    {
        if (this->db().time().value()<period*(n)+period_duty)
        {
            operator==(-amplitude_);
        }
        else if (this->db().time().value()>period*(n)+period_duty)
        {
            operator==(0);
        }
    }
    else if (mode_ == "bias")
    {
        if (this->db().time().value()<period*(n)+period_duty)
        {
            operator==(amplitude_+bias_);
        }
        else if (this->db().time().value()>period*(n)+period_duty)
        {
            operator==(-amplitude_+bias_);
        }
    }
    else
    {
        FatalErrorIn
        (
            "plasmaSquarePotential::updateCoeffs()"
        )   << " model name inconsitent, model = " << mode_
            << exit(FatalError);
    }

    fixedValueFvPatchScalarField::updateCoeffs();
}

void Foam::plasmaSquarePotential::
write(Ostream& os) const
{
    fvPatchScalarField::write(os);
    os.writeKeyword("mode")
        << mode_ << token::END_STATEMENT << nl;
    amplitude_.writeEntry("amplitude", os);
    os.writeKeyword("frequency")
        << frequency_ << token::END_STATEMENT << nl;
    os.writeKeyword("dutyCycle")
        << dutyCycle_ << token::END_STATEMENT << nl;
    writeEntry("value", os);
    os.writeKeyword("bias")
        << bias_ << token::END_STATEMENT << nl;
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
namespace Foam
{
    makePatchTypeField(fvPatchScalarField, plasmaSquarePotential);
}
// ************************************************************************* //



