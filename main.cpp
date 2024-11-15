// src/main.cpp
#include "Patient.h"
#include "Policy.h"
#include "Multithreading.h"
#include <vector>
#include <memory>

int main() {
    // Initialize patients
    auto patient1 = std::make_shared<Patient>(1, "John Doe", 30);
    auto patient2 = std::make_shared<Patient>(2, "Jane Smith", 45);
    std::vector<std::shared_ptr<Patient>> patients = {patient1, patient2};

    // Initialize policies
    StandardPolicy policy;

    // Apply policies using multithreading
    std::vector<std::function<void()>> tasks;
    for (auto& patient : patients) {
        tasks.push_back([&]() { policy.apply(*patient); patient->display(); });
    }

    parallelProcess(tasks);

    return 0;
}
