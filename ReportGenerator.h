#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H

#include "Patient.h"
#include <vector>
#include <memory>
#include <string>
#include <map>

class ReportGenerator {
public:
    static void generateSimulationReport(const std::vector<std::shared_ptr<Patient>>& patients, const std::string& filename);
    static void saveSyntheticPopulation(const std::vector<std::shared_ptr<Patient>>& patients, const std::string& filename);
    static void generatePopulationMetricsReport(const std::map<std::string, double>& metrics, const std::string& filename);
};

#endif // REPORTGENERATOR_H

