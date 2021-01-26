	if (switch_ == "on")
	{
		if (runTime.value() >= startWriteSpatioTemporal)
		{
		// curTimeIndex_ is current time index
		// return the tie index of the field
		// int curTimeIndex_ = runTime.timeIndex();

		// So this one specifies when to start writing things into the solver
		// Modulo finds the remainder. When modulo is 0, it writes into the thing
			if (counter_0 == writeFrequency_)
			{
				// defines the stream function in order to be able to 
				// get an output 

				// required variables to be updated as the simulations run
				const volScalarField& Phi_ = mesh.lookupObject<volScalarField>("Phi");
				const volVectorField& E_x = mesh.lookupObject<volVectorField>("E");

			    volVectorField netChargeFlux_
			    (
			    	IOobject
			    	(
			    		"netChargeFlux_",
			    		mesh.time().timeName(),
			    		mesh,
			    		IOobject::NO_READ,
			    		IOobject::NO_WRITE
			    	),
			    	mspm().netChargeFlux()
			    );

				volScalarField Te
			    (
			        IOobject
			        (
			            "Te",
			            runTime.timeName(),
			            mesh,
			            IOobject::NO_READ
			        ),
			        thermo.Te()
			    ); 

			    volScalarField electron__
			    (
			    	IOobject
			    	(
			    		"electron__",
			    		mesh.time().timeName(),
			    		mesh,
			    		IOobject::NO_READ,
			    		IOobject::NO_WRITE
			    	),
			    	mspm().N(electron)
			    );

			    volScalarField Arp1__
			    (
			    	IOobject
			    	(
			    		"Arp1__",
			    		mesh.time().timeName(),
			    		mesh,
			    		IOobject::NO_READ,
			    		IOobject::NO_WRITE
			    	),
			    	mspm().N(Arp1_)
			    );

			    volScalarField volume_
			    (
			    	IOobject
			    	(
			    		"volume_",
			    		E_x.mesh().time().timeName(),
			    		E_x.mesh(),
			    		IOobject::NO_READ,
			    		IOobject::NO_WRITE
			    	),
			    	E_x.mesh(),
					dimensionedScalar("zero", dimensionSet(0, 0, 0, 1, 0), 0.0)
			    );
			    volume_.internalField() = E_x.mesh().V();

		        volVectorField ddtE_x
			    (
			    	IOobject
			    	(
			    		"ddtE_x",
			    		mesh.time().timeName(),
			    		mesh,
			    		IOobject::NO_READ,
			    		IOobject::NO_WRITE
			    	),
			    	fvc::ddt(E_x)
			    ); 

		        volScalarField power__
			    (
			    	IOobject
			    	(
			    		"power__",
			    		mesh.time().timeName(),
			    		mesh,
			    		IOobject::NO_READ,
			    		IOobject::NO_WRITE
			    	),
			    	volume_*((plasmaConstants::eCharge*netChargeFlux_.component(0)+plasmaConstants::epsilon0*ddtE_x.component(0))*E_x.component(0))
			    );

		     	volScalarField currentDensity
			     (
			     	IOobject
			     	(
			     		"currentDensity",
			     		mesh.time().timeName(),
			     		mesh,
			     		IOobject::NO_READ,
			     		IOobject::NO_WRITE
			     	),
			     	((plasmaConstants::eCharge*netChargeFlux_.component(0)+plasmaConstants::epsilon0*ddtE_x.component(0)))
			     );

		    	volScalarField conductionCurrent_
			     (
			     	IOobject
			     	(
			     		"conductionCurrent_",
			     		mesh.time().timeName(),
			     		mesh,
			     		IOobject::NO_READ,
			     		IOobject::NO_WRITE
			     	),
			    		(plasmaConstants::eCharge*netChargeFlux_.component(0))
			     );

			    volScalarField displacementCurrent_ 
			     (
			     	IOobject
			     	(
			     		"displacementCurrent_",
			     		mesh.time().timeName(),
			     		mesh,
			     		IOobject::NO_READ,
			     		IOobject::NO_WRITE
			     	),
			     	((plasmaConstants::epsilon0*ddtE_x.component(0)))
			     );

			    volVectorField electronConvectiveFlux0 
			     (
			     	IOobject
			     	(
			     		"electronConvectiveFlux0",
			     		mesh.time().timeName(),
			     		mesh,
			     		IOobject::NO_READ,
			     		IOobject::NO_WRITE
			     	),
			     	mspm().electronConvectiveFlux()
			     );

			    volScalarField electronPower_
			    (
			    	IOobject
			    	(
			    		"electronPower_",
			    		mesh.time().timeName(),
			    		mesh,
			    		IOobject::NO_READ,
			    		IOobject::NO_WRITE
			    	),
			    	mag(volume_*(plasmaConstants::eCharge*electronConvectiveFlux0.component(0)*E_x.component(0)))
			    );

				// E_x
				outputProbe_ =
				new OFstream
				(
					runTime.path()
					/"spatioTemporalProbe"/"E_x"
					/"E_x_"+runTime.timeName()+".dat"
				);

				(*outputProbe_) << "Time (s)" << tab << "Position (m)" << tab << "E_x" << endl; 

				outputProbe_->precision(15);

				forAll(E_x,cellI)
				{
			        (*outputProbe_) << runTime.value() << tab
			        << xCoord[cellI].component(0) << tab
			        << E_x[cellI].component(0) << endl; 
				}
				outputProbe_ -> ~Ostream();  

				// Phi_
				outputProbe_ = 
				new OFstream
				(
		                runTime.path()
		               /"spatioTemporalProbe"/"Phi_"
		               /"Phi__"+runTime.timeName()+".dat"
				);

				(*outputProbe_) << "Time (s)" << tab << "Position (m)" << tab << "Phi" << endl; 

				outputProbe_->precision(15);

				forAll(Phi_, cellI)
				{
			        (*outputProbe_) << runTime.value() << tab
			        << xCoord[cellI].component(0) << tab
			        << Phi_[cellI] << endl; 
				}
				outputProbe_ -> ~Ostream(); 
				  
				// Te 
				outputProbe_ =
				new OFstream
				(
					runTime.path()
					/"spatioTemporalProbe"/"Te"
					/"Te_"+runTime.timeName()+".dat"
				);

				(*outputProbe_) << "Time (s)" << tab << "Position (m)" << tab << "Te" << endl; 

				outputProbe_->precision(15);

				forAll(Te,cellI)
				{
			        (*outputProbe_) << runTime.value() << tab
			        << xCoord[cellI].component(0) << tab
			        << Te[cellI] << endl; 
				}
				outputProbe_ -> ~Ostream(); 
				  
				// electron
				outputProbe_ =
				new OFstream
				(
					runTime.path()
					/"spatioTemporalProbe"/"electron"
					/"electron_"+runTime.timeName()+".dat"
				);

				(*outputProbe_) << "Time (s)" << tab << "Position (m)" << tab << "electron" << endl; 

				outputProbe_->precision(15);

				forAll(electron__,cellI)
				{
			        (*outputProbe_) << runTime.value() << tab
			        << xCoord[cellI].component(0) << tab
			        << electron__[cellI] << endl; 
				}
				outputProbe_ -> ~Ostream(); 

				// Arp1
				outputProbe_ =
				new OFstream
				(
					runTime.path()
					/"spatioTemporalProbe"/"Arp1"
					/"Arp1_"+runTime.timeName()+".dat"
				);

				(*outputProbe_) << "Time (s)" << tab << "Position (m)" << tab << "Arp1" << endl; 

				outputProbe_->precision(10);

				forAll(Arp1__,cellI)
				{
			        (*outputProbe_) << runTime.value() << tab
			        << xCoord[cellI].component(0) << tab
			        << Arp1__[cellI] << endl; 
				}
				outputProbe_ -> ~Ostream(); 

				// instantaneous power
				outputProbe_ = 
				new OFstream
				(
					runTime.path()
					/"spatioTemporalProbe"/"power"
					/"pW"+runTime.timeName()+".dat"
				);

				(*outputProbe_) << "Time (s)" << tab << "Position (m)" << tab << "power" << endl; 

				outputProbe_->precision(15);

				forAll(power__,cellI)
				{
					(*outputProbe_) << runTime.value() << tab
					<< xCoord[cellI].component(0) << tab
					<< power__[cellI] << endl;
				}
				outputProbe_ -> ~Ostream(); 

				// current density
				outputProbe_ = 
				new OFstream
				(
					runTime.path()
					/"spatioTemporalProbe"/"currentDensity"
					/"cD_"+runTime.timeName()+".dat"
				);

				(*outputProbe_) << "Time (s)" << tab << "Position (m)" << tab << "currentDensity" << endl; 

				outputProbe_->precision(15);

				forAll(currentDensity,cellI)
				{
					(*outputProbe_) << runTime.value() << tab
					<< xCoord[cellI].component(0) << tab
					<< currentDensity[cellI] << endl;
				}
				outputProbe_ -> ~Ostream(); 

				// current by electric field
				outputProbe_ = 
				new OFstream
				(
					runTime.path()
					/"spatioTemporalProbe"/"displacementCurrent"
					/"dC_"+runTime.timeName()+".dat"
				);

				(*outputProbe_) << "Time (s)" << tab << "Position (m)" << tab << "displacementCurrent" << endl; 

				outputProbe_->precision(15);

				forAll(displacementCurrent_,cellI)
				{
					(*outputProbe_) << runTime.value() << tab
					<< xCoord[cellI].component(0) << tab
					<< displacementCurrent_[cellI] << endl;
				}
				outputProbe_ -> ~Ostream(); 

				// current by conduction 
				outputProbe_ = 
				new OFstream
				(
					runTime.path()
					/"spatioTemporalProbe"/"conductionCurrent"
					/"cC_"+runTime.timeName()+".dat"
				);

				(*outputProbe_) << "Time (s)" << tab << "Position (m)" << tab << "conductionCurrent" << endl; 

				outputProbe_->precision(15);

				forAll(conductionCurrent_,cellI)
				{
					(*outputProbe_) << runTime.value() << tab
					<< xCoord[cellI].component(0) << tab
					<< conductionCurrent_[cellI] << endl;
				}
				outputProbe_ -> ~Ostream(); 

				// power by flux of electrons 
				outputProbe_ = 
				new OFstream
				(
					runTime.path()
					/"spatioTemporalProbe"/"electronsPower"
					/"electronsPower_"+runTime.timeName()+".dat"
				);

				(*outputProbe_) << "Time (s)" << tab << "Position (m)" << tab << "electronsPower" << endl; 

				outputProbe_->precision(15);

				forAll(electronPower_,cellI)
				{
					(*outputProbe_) << runTime.value() << tab
					<< xCoord[cellI].component(0) << tab
					<< electronPower_[cellI] << endl;
				}
				outputProbe_ -> ~Ostream();

				// volume 
				outputProbe_ = 
				new OFstream
				(
					runTime.path()
					/"spatioTemporalProbe"/"Volume"
					/"Volume_"+runTime.timeName()+".dat"
				);

				(*outputProbe_) << "Time (s)" << tab << "Position (m)" << tab << "Volume" << endl; 

				outputProbe_->precision(15);

				forAll(volume_,cellI)
				{
					(*outputProbe_) << runTime.value() << tab
					<< xCoord[cellI].component(0) << tab
					<< volume_[cellI]*(1E06) << endl;
				}
				outputProbe_ -> ~Ostream();

				// power by ratio of power-electrons and power-general 
				// outputProbe_ = 
				// new OFstream
				// (
				// 	runTime.path()
				// 	/"spatioTemporalProbe"/"electronPlasmaPower"
				// 	/"electronPlasmaPower_"+runTime.timeName()+".dat"
				// );

				// (*outputProbe_) << "Time (s)" << tab << "Position (m)" << tab << "electronsPlasmaPower" << endl; 

				// outputProbe_->precision(15);

				// forAll(electronPower_,cellI)
				// {
				// 	(*outputProbe_) << runTime.value() << tab
				// 	<< xCoord[cellI].component(0) << tab
				// 	<< electronPower_[cellI]/power__[cellI] << endl;
				// }
				// outputProbe_ -> ~Ostream();  

				// counter_0 gets reset 
				counter_0 = 1;
			}

			else
			{
				// counter_0 start counting 
				counter_0 = counter_0+1; 
			}
		}
	}


