// src/Policy.cpp
#include "Patient.h"
#include "Policy.h"
#include <iostream>

// Preventive care reduces risk factors
void PreventiveCarePolicy::apply(Patient& patient) const {
    if (patient.getRiskFactors().size() > 0) {
        patient.setHealthScore(patient.getHealthScore() + 10); // Boost health for preventive measures
        std::cout << "Preventive care applied.\n";
    }
}

// Aggressive policy for severe cases
void AggressivePolicy::apply(Patient& patient) const {
    patient.setHealthScore(patient.getHealthScore() - 20); // More intensive treatment with side effects
    std::cout << "Aggressive treatment applied.\n";
}

