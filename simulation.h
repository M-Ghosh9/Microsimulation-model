// include/Simulation.h
#ifndef SIMULATION_H
#define SIMULATION_H

#include "Patient.h"
#include "Policy.h"
#include <vector>
#include <memory>
#include <execution>

class Simulation {
public:
    Simulation(std::shared_ptr<Policy> policy);
    void generatePopulation(int size);
    void run();
    void generateReport() const;

private:
    std::vector<std::shared_ptr<Patient>> patients_;
    std::shared_ptr<Policy> policy_;
};

#endif // SIMULATION_H
