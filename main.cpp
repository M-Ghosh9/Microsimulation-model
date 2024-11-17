// src/main.cpp
#include "Patient.h"
#include "Policy.h"
#include "Simulation.h"
#include <memory>

int main() {
    auto preventivePolicy = std::make_shared<PreventiveCarePolicy>();
    auto aggressivePolicy = std::make_shared<AggressivePolicy>();

    Simulation simulation(preventivePolicy);
    simulation.generatePopulation(1000);
    simulation.run();
    simulation.generateReport();

    // Optionally, run with a different policy
    Simulation simulation2(aggressivePolicy);
    simulation2.generatePopulation(1000);
    simulation2.run();
    simulation2.generateReport();

    return 0;
}


