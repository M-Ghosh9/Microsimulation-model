// src/Simulation.cpp
#include "Simulation.h"
#include "HealthPredictor.h"
#include <iostream>
#include <algorithm>
#include <execution>

Simulation::Simulation(std::shared_ptr<Policy> policy)
    : policy_(policy) {}

void Simulation::generatePopulation(int size) {
    for (int i = 0; i < size; ++i) {
        patients_.emplace_back(std::make_shared<Patient>(i + 1));
    }
}

void Simulation::run() {
    std::for_each(std::execution::par, patients_.begin(), patients_.end(),
                  [this](auto& patient) { 
                      policy_->apply(*patient); 
                      double risk = HealthPredictor::predictHealthRisk(*patient);
                      std::cout << "Predicted Risk: " << risk << "%\n";
                  });
}

void Simulation::generateReport() const {
    std::cout << "Simulation Report:\n";
    for (const auto& patient : patients_) {
        patient->display();
    }
    std::cout << "Total Patients Simulated: " << patients_.size() << '\n';
}
