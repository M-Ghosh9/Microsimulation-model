// src/Simulation.cpp
#include "Simulation.h"
#include <iostream>
#include <algorithm>
#include <execution>

Simulation::Simulation(std::shared_ptr<Policy> policy)
    : policy_(policy) {}

// Generate a synthetic population of patients
void Simulation::generatePopulation(int size) {
    for (int i = 0; i < size; ++i) {
        patients_.emplace_back(std::make_shared<Patient>(i + 1));
    }
}

void Simulation::run() {
    // Apply the policy to each patient using parallel execution
    std::for_each(std::execution::par, patients_.begin(), patients_.end(),
                  [this](auto& patient) { policy_->apply(*patient); });
}

void Simulation::generateReport() const {
    std::cout << "Simulation Report:\n";
    int count = 0;
    for (const auto& patient : patients_) {
        if (++count <= 10) patient->display(); // Show details for first 10 patients only
    }
    std::cout << "Total Patients Simulated: " << patients_.size() << '\n';
}
