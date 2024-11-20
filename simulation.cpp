// src/Simulation.cpp
#include "Simulation.h"
#include "HealthPredictor.h"
#include "ReportGenerator.h"
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
                      patient->display(); // Optionally log patient data
                  });
}

void Simulation::generateReport() const {
    ReportGenerator::generateSimulationReport(patients_, "simulation_report.txt");
    ReportGenerator::saveSyntheticPopulation(patients_, "patients_data.csv");

    // Generate population-level metrics
    auto metrics = calculatePopulationMetrics();
    ReportGenerator::generatePopulationMetricsReport(metrics, "population_metrics.txt");
}

std::map<std::string, double> Simulation::calculatePopulationMetrics() const {
    double totalHealthScore = 0.0;
    int totalPatients = patients_.size();
    int atRiskCount = 0;
    int diabetesCount = 0;
    int hypertensionCount = 0;

    for (const auto& patient : patients_) {
        totalHealthScore += patient->getHealthScore();

        // Check risk factors
        for (const auto& factor : patient->getRiskFactors()) {
            if (factor == "Diabetes") diabetesCount++;
            if (factor == "Hypertension") hypertensionCount++;
        }

        // Count patients with any risk factor
        if (!patient->getRiskFactors().empty()) atRiskCount++;
    }

    return {
        {"Average Health Score", totalHealthScore / totalPatients},
        {"Proportion At Risk", static_cast<double>(atRiskCount) / totalPatients * 100},
        {"Proportion with Diabetes", static_cast<double>(diabetesCount) / totalPatients * 100},
        {"Proportion with Hypertension", static_cast<double>(hypertensionCount) / totalPatients * 100}
    };
}


