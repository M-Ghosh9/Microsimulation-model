// include/Patient.h
#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <memory>

class Treatment;

class Patient {
public:
    Patient(int id, const std::string& name, int age);
    void applyTreatment(const Treatment& treatment);
    double getHealthScore() const;
    void setHealthScore(double score);
    void display() const;

private:
    int id_;
    std::string name_;
    int age_;
    double healthScore_;
};

#endif // PATIENT_H
