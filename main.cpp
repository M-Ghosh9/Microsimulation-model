// src/main.cpp
#include "Patient.h"
#include "Policy.h"
#include "Simulation.h"
#include <memory>

int main() {
    // Initialize a policy (can switch to AggressivePolicy for comparison)
    auto policy = std::make_shared<StandardPolicy>();

    // Create Simulation Engine
    Simulation simulation(policy);

    // Generate a synthetic population of 1000 patients
    simulation.generatePopulation(1000);

    // Run the simulation
    simulation.run();

    // Generate and display the report
    simulation.generateReport();

    return 0;
}
