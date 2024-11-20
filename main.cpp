// src/main.cpp
#include "Simulation.h"
#include "Policy.h"
#include <iostream>
#include <memory>

int main() {
    auto policy = std::make_shared<PreventiveCarePolicy>();
    Simulation simulation(policy);

    // Generate a large synthetic population (e.g., 100,000)
    simulation.generatePopulation(100000);
    simulation.run();

    // Generate reports
    simulation.generateReport();

    std::cout << "Simulation completed. Reports generated:\n"
              << "- simulation_report.txt\n"
              << "- patients_data.csv\n"
              << "- population_metrics.txt\n";

    return 0;
}


