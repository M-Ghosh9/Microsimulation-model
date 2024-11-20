// include/Patient.h
#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <vector>
#include <memory>

class Treatment;

class Patient {
public:
    // Constructors
    Patient(int id);
    Patient(int id, const std::string& name, int age, const std::string& gender,
            const std::string& ethnicity, const std::vector<std::string>& riskFactors);

    // Methods
    void applyTreatment(const Treatment& treatment);
    double getHealthScore() const;
    void display() const;
    void setHealthScore(double score);

    // Getters for new attributes
    const std::string& getGender() const;
    const std::string& getEthnicity() const;
    const std::vector<std::string>& getRiskFactors() const;

private:
    int id_;
    std::string name_;
    int age_;
    std::string gender_;
    std::string ethnicity_;
    std::vector<std::string> riskFactors_;
    double healthScore_;
};

#endif // PATIENT_H
