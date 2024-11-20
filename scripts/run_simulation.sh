#!/bin/bash

# Compile the code
echo "Compiling the code..."
g++ src/*.cpp -I include -o microsimulation.exe

# Run the simulation
echo "Running the simulation..."
./microsimulation.exe

# Display the report
echo "Simulation completed. Report saved to simulation_report.txt."
echo "Synthetic population saved to patients_data.csv."
cat simulation_report.txt
