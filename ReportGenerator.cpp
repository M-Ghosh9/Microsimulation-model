#include "ReportGenerator.h"
#include <fstream>
#include <iomanip>

void ReportGenerator::generateSimulationReport(const std::vector<std::shared_ptr<Patient>>& patients, const std::string& filename) {
    std::ofstream reportFile(filename);

    if (!reportFile.is_open()) {
        throw std::runtime_error("Unable to open file: " + filename);
    }

    reportFile << "Simulation Report:\n\n";
    for (const auto& patient : patients) {
        reportFile << "ID: " << patient->getId()
                   << ", Age: " << patient->getAge()
                   << ", Gender: " << patient->getGender()
                   << ", Ethnicity: " << patient->getEthnicity()
                   << ", Health Score: " << std::fixed << std::setprecision(2) << patient->getHealthScore()
                   << ", Risk Factors: ";
        for (const auto& risk : patient->getRiskFactors()) {
            reportFile << risk << " ";
        }
        reportFile << "\n";
    }
    reportFile << "\nTotal Patients Simulated: " << patients.size() << "\n";

    reportFile.close();
}

void ReportGenerator::saveSyntheticPopulation(const std::vector<std::shared_ptr<Patient>>& patients, const std::string& filename) {
    std::ofstream csvFile(filename);

    if (!csvFile.is_open()) {
        throw std::runtime_error("Unable to open file: " + filename);
    }

    csvFile << "ID,Age,Gender,Ethnicity,HealthScore,RiskFactors\n";
    for (const auto& patient : patients) {
        csvFile << patient->getId() << ","
                << patient->getAge() << ","
                << patient->getGender() << ","
                << patient->getEthnicity() << ","
                << patient->getHealthScore() << ",";
        for (size_t i = 0; i < patient->getRiskFactors().size(); ++i) {
            csvFile << patient->getRiskFactors()[i];
            if (i < patient->getRiskFactors().size() - 1) {
                csvFile << ";";
            }
        }
        csvFile << "\n";
    }

    csvFile.close();
}

void ReportGenerator::generatePopulationMetricsReport(const std::map<std::string, double>& metrics, const std::string& filename) {
    std::ofstream metricsFile(filename);

    if (!metricsFile.is_open()) {
        throw std::runtime_error("Unable to open file: " + filename);
    }

    metricsFile << "Population Metrics Report:\n\n";
    for (const auto& [metric, value] : metrics) {
        metricsFile << metric << ": " << std::fixed << std::setprecision(2) << value << "%\n";
    }

    metricsFile.close();
}
