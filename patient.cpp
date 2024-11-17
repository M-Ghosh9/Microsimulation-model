// src/Patient.cpp
#include "Patient.h"
#include "Treatment.h"
#include <iostream>
#include <random>

// Random number generator
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> age_dist(20, 80);
std::uniform_real_distribution<> health_dist(50.0, 100.0);

Patient::Patient(int id, const std::string& name, int age) 
    : id_(id), name_(name), age_(age), healthScore_(health_dist(gen)) {}

// Additional constructor for random patient generation
Patient::Patient(int id)
    : id_(id), name_("Patient_" + std::to_string(id)), age_(age_dist(gen)), healthScore_(health_dist(gen)) {}

void Patient::applyTreatment(const Treatment& treatment) {
    healthScore_ -= treatment.getEfficacy();
    if (healthScore_ < 0) healthScore_ = 0; // Clamp health score to non-negative
}

double Patient::getHealthScore() const { return healthScore_; }
void Patient::display() const {
    std::cout << "ID: " << id_ << ", Age: " << age_ 
              << ", Health Score: " << healthScore_ << '\n';
}
