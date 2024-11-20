#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H

#include "Patient.h"
#include <vector>
#include <memory>
#include <string>

class ReportGenerator {
public:
    static void generateSimulationReport(const std::vector<std::shared_ptr<Patient>>& patients, const std::string& filename);
    static void saveSyntheticPopulation(const std::vector<std::shared_ptr<Patient>>& patients, const std::string& filename);
};

#endif // REPORTGENERATOR_H
