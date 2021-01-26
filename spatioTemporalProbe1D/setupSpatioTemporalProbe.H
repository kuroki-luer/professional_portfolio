	// defines the stream function in order to be able to 
	// get an output 
	OFstream* outputProbe_;

	// count of the cells, of course, main region
	// int cellCount_ = mesh.cells().size(); 

	// int writeFrequency_ = 1000; 
	scalar counter_0 = 1;

	IOdictionary runTimeUtilities
	(
	    IOobject
	    (
	        "runTimeUtilities",  
	          		   // dictionary name
	        runTime.constant(),     	   // dict is found in "constant"
	        mesh,                          // registry for the dict
	        IOobject::MUST_READ,           // must exist, otherwise failure
	        IOobject::NO_WRITE             // dict is only read by the solver
	    )
	);

	scalar writeFrequency_ = readScalar(runTimeUtilities.subDict("spatioTemporalProbe").lookup("writeFrequency")); 
	word switch_ = word(runTimeUtilities.subDict("spatioTemporalProbe").lookup("switch")); 
	scalar frequency_0L = readScalar(runTimeUtilities.subDict("spatioTemporalProbe").lookup("frequencyOperation"));
	scalar cycleCompletion = readScalar(runTimeUtilities.subDict("spatioTemporalProbe").lookup("cyclesToEndTime"));

	scalar startWriteSpatioTemporal = runTime.endTime().value() - (1/frequency_0L)*cycleCompletion; 

	// general definition of the 3D fields
	const vectorField& xCoord = mesh.C().internalField();

	word electron = "electron";
	word Arp1_ = "Arp1";

	if (switch_ == "on")
	{

		// nSolutionD - dimension() of the mesh
		if (mesh.nSolutionD() != 1)
		{
			// this will give an error, and abort the program
			FatalErrorIn("electricalCharacteristics::")
				<< "only 1D meshes are supported. "
				<< abort(FatalError); 
		}

		if (Pstream::master())
		{
			// runTime defined by emcModels
			// processorCase() is regarding if the process is running
			// in parallel
			if (!runTime.processorCase())
			{
				// this is just the ROOT folder
				mkDir
				(
					runTime.path()
					/"spatioTemporalProbe"
				);

				mkDir
				(
					runTime.path()
					/"spatioTemporalProbe"/"electron"
				);

				mkDir
				(
					runTime.path()
					/"spatioTemporalProbe"/"Phi_"
				);

				mkDir
				(
					runTime.path()
					/"spatioTemporalProbe"/"Te"
				);

				mkDir
				(
					runTime.path()
					/"spatioTemporalProbe"/"Arp1"
				);

				mkDir
				(
					runTime.path()
					/"spatioTemporalProbe"/"E_x"
				);

				mkDir
				(
					runTime.path()
					/"spatioTemporalProbe"/"power"
				);

				mkDir
				(
					runTime.path()
					/"spatioTemporalProbe"/"currentDensity"
				);

				mkDir
				(
					runTime.path()
					/"spatioTemporalProbe"/"conductionCurrent"
				);

				mkDir
				(
					runTime.path()
					/"spatioTemporalProbe"/"displacementCurrent"
				);

				mkDir
				(
					runTime.path()
					/"spatioTemporalProbe"/"electronsPower"
				);

				mkDir
				(
					runTime.path()
					/"spatioTemporalProbe"/"Volume"
				);

				outputProbe_ =
				new OFstream
				(
					runTime.path()
					/"spatioTemporalProbe"/"electron"
					/"electron_"+runTime.timeName()+".dat"
				);

				(*outputProbe_) << "Time (s)" << tab << "Position (m)" << tab << "electron" << endl; 

				outputProbe_ =
				new OFstream
				(
					runTime.path()
					/"spatioTemporalProbe"/"Phi_"
					/"Phi__"+runTime.timeName()+".dat"
				);

				(*outputProbe_) << "Time (s)" << tab << "Position (m)" << tab << "Phi" << endl; 

				outputProbe_ =
				new OFstream
				(
					runTime.path()
					/"spatioTemporalProbe"/"Te"
					/"Te_"+runTime.timeName()+".dat"
				);

				(*outputProbe_) << "Time (s)" << tab << "Position (m)" << tab << "Te" << endl; 

				outputProbe_ =
				new OFstream
				(
					runTime.path()
					/"spatioTemporalProbe"/"Arp1"
					/"Arp1_"+runTime.timeName()+".dat"
				);

				(*outputProbe_) << "Time (s)" << tab << "Position (m)" << tab << "Arp1" << endl;

				outputProbe_ =
				new OFstream
				(
					runTime.path()
					/"spatioTemporalProbe"/"E_x"
					/"E_x_"+runTime.timeName()+".dat"
				);

				(*outputProbe_) << "Time (s)" << tab << "Position (m)" << tab << "E_x" << endl; 

				outputProbe_ =
				new OFstream
				(
					runTime.path()
					/"spatioTemporalProbe"/"power"
					/"power_"+runTime.timeName()+".dat"
				);

				(*outputProbe_) << "Time (s)" << tab << "Position (m)" << tab << "power" << endl; 

				outputProbe_ =
				new OFstream
				(
					runTime.path()
					/"spatioTemporalProbe"/"currentDensity"
					/"currentDensity_"+runTime.timeName()+".dat"
				);

				(*outputProbe_) << "Time (s)" << tab << "Position (m)" << tab << "currentDensity" << endl; 

				outputProbe_ =
				new OFstream
				(
					runTime.path()
					/"spatioTemporalProbe"/"conductionCurrent"
					/"conductionCurrent_"+runTime.timeName()+".dat"
				);

				(*outputProbe_) << "Time (s)" << tab << "Position (m)" << tab << "conductionCurrent" << endl; 

				outputProbe_ =
				new OFstream
				(
					runTime.path()
					/"spatioTemporalProbe"/"displacementCurrent"
					/"displacementCurrent_"+runTime.timeName()+".dat"
				);

				(*outputProbe_) << "Time (s)" << tab << "Position (m)" << tab << "displacementCurrent" << endl; 

				outputProbe_ = 
				new OFstream
				(
					runTime.path()
					/"spatioTemporalProbe"/"electronsPower"
					/"electronsPower_"+runTime.timeName()+".dat"
				);

				(*outputProbe_) << "Time (s)" << tab << "Position (m)" << tab << "electronsPower" << endl; 

				// outputProbe_ = 
				// new OFstream
				// (
				// 	runTime.path()
				// 	/"spatioTemporalProbe"/"electronPlasmaPower"
				// 	/"electronPlasmaPower_"+runTime.timeName()+".dat"
				// );

				// (*outputProbe_) << "Time (s)" << tab << "Position (m)" << tab << "electronsPlasmaPower" << endl; 
			}
			
			else
			{
				// this will give an error, and abort the program
				FatalErrorIn("electricalCharacteristics::")
				<< "only 1D meshes are supported. "
				<< abort(FatalError); 
			}
		}
	}	



