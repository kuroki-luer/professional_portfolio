The following code compares the power in the plasma and automatically modulates the voltage input in order for the power input to match the total power in the plasma. Sinusoidal and unipolar pulsed waveforms are available, althought new waveforms are expected in the future. 

This algorithm in particular couples the input voltage in the presence of a dielectric layer. Since the dielectric layer and the plasmas are considered different regions in openFoam, this algorithm works in conjunction with UnipolarPulsedExtendedPotential in order to define the input voltage boundary condition
