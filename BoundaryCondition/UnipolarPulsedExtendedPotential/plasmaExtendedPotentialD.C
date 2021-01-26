/*---------------------------------------------------------------------------*\
Copyright (C) 2018 by the LUEUR authors

License
This project is licensed under The 3-Clause BSD License. For further information
look for license file include with distribution.

\*---------------------------------------------------------------------------*/

#include "plasmaExtendedPotentialD.H"
#include "addToRunTimeSelectionTable.H"
#include "fvPatchFieldMapper.H"
#include "volFields.H"

namespace Foam
{
// * * * * * * * * * * * * * Protected Member Functions  * * * * * * * * * * //

Foam::scalarField
Foam::plasmaExtendedPotentialD::voltage() const
{
    // Extract the dictionary from the database
    IOdictionary& voltageDictD = const_cast<IOdictionary&>(db().lookupObject<IOdictionary>
    (
        // if I put voltageDictDX it doesnt even exist so RIP that's not the way to go
        "voltageDictD"
    ));

    // Extracting scalar value
    scalar voltage(voltageDictD.lookupOrDefault<scalar>("voltageD",0.0));
    
    return tmp<scalarField>
    (
        new scalarField(this->size(), voltage)
    );
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //
Foam::plasmaExtendedPotentialD::
plasmaExtendedPotentialD
(
    const fvPatch& p,
    const DimensionedField<scalar, volMesh>& iF
)
:
    fixedValueFvPatchScalarField(p, iF)
{}


Foam::plasmaExtendedPotentialD::
plasmaExtendedPotentialD
(
    const fvPatch& p,
    const DimensionedField<scalar, volMesh>& iF,
    const dictionary& dict
)
:
    fixedValueFvPatchScalarField(p, iF)
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

Foam::plasmaExtendedPotentialD::
plasmaExtendedPotentialD
(
    const plasmaExtendedPotentialD& ptf,
    const fvPatch& p,
    const DimensionedField<scalar, volMesh>& iF,
    const fvPatchFieldMapper& mapper
)
:
    fixedValueFvPatchScalarField(ptf, p, iF, mapper)
{}


Foam::plasmaExtendedPotentialD::
plasmaExtendedPotentialD
(
    const plasmaExtendedPotentialD& tppsf
)
:
    fixedValueFvPatchScalarField(tppsf)
{}


Foam::plasmaExtendedPotentialD::
plasmaExtendedPotentialD
(
    const plasmaExtendedPotentialD& tppsf,
    const DimensionedField<scalar, volMesh>& iF
)
:
    fixedValueFvPatchScalarField(tppsf, iF)
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //
void Foam::plasmaExtendedPotentialD::
autoMap
(
    const fvPatchFieldMapper& m
)
{
    plasmaExtendedPotentialD::autoMap(m);
}


void Foam::plasmaExtendedPotentialD::
rmap
(
    const fvPatchScalarField& ptf,
    const labelList& addr
)
{
    plasmaExtendedPotentialD::rmap(ptf, addr);
}

void Foam::plasmaExtendedPotentialD::updateCoeffs()
{
    if (updated())
    {
        return;
    }

    operator==(voltage());

    fixedValueFvPatchScalarField::updateCoeffs();
}

void Foam::plasmaExtendedPotentialD::
write(Ostream& os) const
{
    fvPatchScalarField::write(os);
    writeEntry("value", os);
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

makePatchTypeField(fvPatchScalarField, plasmaExtendedPotentialD);

}
// ************************************************************************* //
