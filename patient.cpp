// src/Patient.cpp
#include "Patient.h"
#include "Treatment.h"
#include <iostream>

Patient::Patient(int id, const std::string& name, int age) 
    : id_(id), name_(name), age_(age), healthScore_(100.0) {}

void Patient::applyTreatment(const Treatment& treatment) {
    healthScore_ -= treatment.getEfficacy(); // Simple simulation effect
}

double Patient::getHealthScore() const { return healthScore_; }

void Patient::setHealthScore(double score) { healthScore_ = score; }

void Patient::display() const {
    std::cout << "Patient ID: " << id_ 
              << ", Name: " << name_ 
              << ", Age: " << age_ 
              << ", Health Score: " << healthScore_ << '\n';
}
