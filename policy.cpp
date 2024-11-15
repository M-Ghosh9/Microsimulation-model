// src/Policy.cpp
#include "Policy.h"

void StandardPolicy::apply(Patient& patient) {
    patient.setHealthScore(patient.getHealthScore() - 10); // Moderate effect
}

void AggressivePolicy::apply(Patient& patient) {
    patient.setHealthScore(patient.getHealthScore() - 20); // Stronger effect
}
