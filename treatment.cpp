#include "Treatment.h"

// Constructor
Treatment::Treatment(const std::string& name, double efficacy)
    : name_(name), efficacy_(efficacy) {}

// Getters
const std::string& Treatment::getName() const {
    return name_;
}

double Treatment::getEfficacy() const {
    return efficacy_;
}
