#include "HealthPredictor.h"

// Simple predictive model based on risk factors, gender, and ethnicity
double HealthPredictor::predictHealthRisk(const Patient& patient) {
    double riskScore = 0.0;
    
    // Base score from health factors
    for (const auto& factor : patient.getRiskFactors()) {
        if (factor == "Diabetes") riskScore += 15.0;
        if (factor == "Hypertension") riskScore += 10.0;
        if (factor == "Obesity") riskScore += 20.0;
        if (factor == "Smoking") riskScore += 25.0;
    }

    // Modifiers based on gender and ethnicity
    if (patient.getGender() == "Male") riskScore += 5.0;
    if (patient.getEthnicity() == "Black") riskScore += 5.0;

    // Normalize risk to be within 0-100
    return std::min(100.0, riskScore);
}
