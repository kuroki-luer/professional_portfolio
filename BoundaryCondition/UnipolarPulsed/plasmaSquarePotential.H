/*---------------------------------------------------------------------------*\
Copyright (C) 2018 by the LUEUR authors

License
This project is licensed under The 3-Clause BSD License. For further information
look for license file include with distribution.

Class
Foam::plasmaSquarePotential

Description
    Abstract base class for electric potential boundary conditions.

SourceFiles
plasmaSquarePotential.C

\*---------------------------------------------------------------------------*/

#ifndef plasmaSquarePotential_H
#define plasmaSquarePotential_H

#include "fixedValueFvPatchFields.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

class plasmaSquarePotential
:
public fixedValueFvPatchScalarField
{
    // Private data
    scalarField amplitude_;
    word mode_;
    scalar frequency_;
    scalar dutyCycle_;
    scalar bias_;
    
  public:

    //- Runtime type information
    TypeName("plasmaSquarePotential");


    // Constructors

    //- Construct from patch and internal field
    plasmaSquarePotential
    (
     const fvPatch&,
     const DimensionedField<scalar, volMesh>&
     );

    //- Construct from patch, internal field and dictionary
    plasmaSquarePotential
    (
     const fvPatch&,
     const DimensionedField<scalar, volMesh>&,
     const dictionary&
     );

    //- Construct by mapping given
    //  plasmaSquarePotential onto a new patch
    plasmaSquarePotential
    (
     const plasmaSquarePotential&,
     const fvPatch&,
     const DimensionedField<scalar, volMesh>&,
     const fvPatchFieldMapper&
     );

    //- Construct as copy
    plasmaSquarePotential
    (
     	const plasmaSquarePotential&
    );

    //- Construct and return a clone
    virtual tmp<fvPatchScalarField> clone() const
    {
      	return tmp<fvPatchScalarField>
		(
		 new plasmaSquarePotential(*this)
		);
    }

    //- Construct as copy setting internal field reference
    plasmaSquarePotential
    (
		 const plasmaSquarePotential&,
		 const DimensionedField<scalar, volMesh>&
    );

    //- Construct and return a clone setting internal field reference
    virtual tmp<fvPatchScalarField> clone
    (
     	const DimensionedField<scalar, volMesh>& iF
    ) const
    {
		return tmp<fvPatchScalarField>
		(
			new plasmaSquarePotential(*this, iF)
		);
    }


    // Member functions

    //- Map (and resize as needed) from self given a mapping object
    virtual void autoMap
    (
        const fvPatchFieldMapper&
    );

    //- Reverse map the given fvPatchField onto this fvPatchField
    virtual void rmap
    (
        const fvPatchScalarField&,
        const labelList&
    );

    //- Update the coefficients associated with the patch field
    virtual void updateCoeffs();

    //- Write
    virtual void write(Ostream&) const;
  };


  // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
