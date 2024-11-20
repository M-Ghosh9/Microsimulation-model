// src/Patient.cpp
#include "Patient.h"
// #include "Treatment.h"
#include <iostream>
#include <random>

// Random generators
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> age_dist(20, 80);
std::uniform_real_distribution<> health_dist(50.0, 100.0);
std::vector<std::string> genders = {"Male", "Female"};
std::vector<std::string> ethnicities = {"Asian", "Black", "White", "Hispanic"};
std::vector<std::string> risk_factors = {"Diabetes", "Hypertension", "Obesity", "Smoking"};

// Constructors
Patient::Patient(int id)
    : id_(id), 
      name_("Patient_" + std::to_string(id)), 
      age_(age_dist(gen)), 
      gender_(genders[gen() % genders.size()]),
      ethnicity_(ethnicities[gen() % ethnicities.size()]),
      healthScore_(health_dist(gen)) {
    int riskCount = gen() % 3; // Randomly assign 0-2 risk factors
    for (int i = 0; i < riskCount; ++i) {
        riskFactors_.push_back(risk_factors[gen() % risk_factors.size()]);
    }
}

void Patient::applyTreatment(const Treatment& treatment) {
    healthScore_ -= treatment.getEfficacy();
    if (healthScore_ < 0) healthScore_ = 0; // Ensure health score is non-negative
}

double Patient::getHealthScore() const { return healthScore_; }

void Patient::setHealthScore(double score) {
    healthScore_ = score;
}

void Patient::display() const {
    std::cout << "ID: " << id_ 
              << ", Age: " << age_ 
              << ", Gender: " << gender_
              << ", Ethnicity: " << ethnicity_ 
              << ", Health Score: " << healthScore_ 
              << ", Risk Factors: ";
    for (const auto& factor : riskFactors_) {
        std::cout << factor << " ";
    }
    std::cout << '\n';
}

// Getters for new attributes
const std::string& Patient::getGender() const { return gender_; }
const std::string& Patient::getEthnicity() const { return ethnicity_; }
const std::vector<std::string>& Patient::getRiskFactors() const { return riskFactors_; }
