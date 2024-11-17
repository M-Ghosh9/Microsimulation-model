#ifndef HEALTHPREDICTOR_H
#define HEALTHPREDICTOR_H

#include "Patient.h"

class HealthPredictor {
public:
    static double predictHealthRisk(const Patient& patient);
};

#endif // HEALTHPREDICTOR_H
