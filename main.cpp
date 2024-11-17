// src/main.cpp
#include "Patient.h"
#include "Policy.h"
#include "Simulation.h"
#include <memory>

int main() {
    auto policy = std::make_shared<StandardPolicy>();
    Simulation simulation(policy);

    // Generate a population of 1000 patients
    simulation.generatePopulation(1000);

    // Run the simulation
    simulation.run();

    // Generate the report
    simulation.generateReport();

    return 0;
}

