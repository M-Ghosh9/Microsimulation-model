#ifndef TREATMENT_H
#define TREATMENT_H

#include <string>

class Treatment {
public:
    // Constructor
    Treatment(const std::string& name, double efficacy);

    // Getters
    const std::string& getName() const;
    double getEfficacy() const;

private:
    std::string name_;
    double efficacy_; // Positive values improve health, negative values represent side effects
};

#endif // TREATMENT_H
