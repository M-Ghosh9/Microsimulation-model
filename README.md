# Microsimulation-model for Healthcare Policy
A C++ application that simulates healthcare policy impacts on patient outcomes. 

## 📚 Project Overview
This project is a C++ application that simulates the impact of various healthcare policies on patient outcomes. It leverages modern C++20/23 features such as Concepts, Ranges, Smart Pointers, and Multithreading to model the effects of healthcare interventions on patient health metrics.

## 🛠️ Features
# Multithreading & Vectorization: Parallel processing for scalability and faster simulations.
# Modern C++: Utilizes Concepts, Ranges, and Smart Pointers for cleaner and efficient code.
# Predictive Modeling: Includes a health predictor to assess disease risks based on patient attributes.
# Simulation Reports: Generates detailed reports on the impact of healthcare policies.
# Modular Design: Easily extendable and maintainable code structure for future enhancements.

## Architecture Diagram
![image](https://github.com/user-attachments/assets/6e8d1dc1-f366-4e27-96da-1c25c9d9d153)


## Class Diagram
![image](https://github.com/user-attachments/assets/68671b42-5e00-46af-a3b5-3e5ad76655d3)

## Sequence Diagram
![image](https://github.com/user-attachments/assets/5686a298-7268-4d9a-9c42-f44f3fd6baa8)

## Use Case Diagram
![image](https://github.com/user-attachments/assets/ea2a3252-a1de-4e03-809f-58668a20fc1f)


## 📂 Project Structure
```plaintext
microsimulation-model/
├── CMakeLists.txt
├── README.md
├── LICENSE
├── docs/
│   ├── architecture.png      # Architecture diagram
│   ├── class_diagram.png     # Class diagram
│   ├── sequence_diagram.png  # Sequence diagram
│   ├── use_case_diagram.png  # Use Case diagram
│   ├── output_diagram.png    # Output structure diagram
│   └── usage_guide.md        # Detailed usage guide
├── include/
│   ├── Patient.h
│   ├── Hospital.h
│   ├── Policy.h
│   ├── Treatment.h
│   ├── Simulation.h
│   ├── HealthPredictor.h
│   └── ReportGenerator.h
├── src/
│   ├── main.cpp
│   ├── Patient.cpp
│   ├── Hospital.cpp
│   ├── Policy.cpp
│   ├── Treatment.cpp
│   ├── Simulation.cpp
│   ├── HealthPredictor.cpp
│   └── ReportGenerator.cpp
├── tests/
│   ├── test_patient.cpp
│   ├── test_simulation.cpp
│   └── CMakeLists.txt
├── data/
│   └── patients_data.csv
├── scripts/
│   ├── run_simulation.sh
│   └── generate_report.sh
└── images/
    ├── architecture.png
    ├── class_diagram.png
    ├── sequence_diagram.png
    ├── use_case_diagram.png
    └── output_diagram.png
``` 

## 🚀 Getting Started
📦 Prerequisites
```plaintext
CMake (version 3.16+)
C++ Compiler (GCC, Clang, or MSVC)
Google Test (for unit testing)
```

## ⚙️ Installation
Clone the repository and build the project using CMake:
```plaintext
git clone https://github.com/M-Ghosh9/Microsimulation-model.git
cd Microsimulation-model
mkdir build
cd build
cmake ..
make
```

## 🏃‍♂️ Running the Simulation
To run the simulation:
```plaintext
./microsimulation
```

## ✅ Running Tests
To run unit tests:
```plaintext
./tests/tests
```

## 📊 Generating Reports
Use the provided script to generate reports:
```plaintext
./scripts/generate_report.sh
```
## Output
```plaintext
Simulation Report:

ID: 1, Age: 67, Gender: Male, Ethnicity: Asian, Health Score: 75.89, Risk Factors: Diabetes Obesity
Predicted Risk: 35.00%

ID: 2, Age: 42, Gender: Female, Ethnicity: White, Health Score: 88.30, Risk Factors: Hypertension
Predicted Risk: 10.00%

ID: 3, Age: 59, Gender: Male, Ethnicity: Black, Health Score: 60.45, Risk Factors: Smoking 
Predicted Risk: 30.00%

ID: 4, Age: 25, Gender: Female, Ethnicity: Hispanic, Health Score: 95.20, Risk Factors: 
Predicted Risk: 0.00%

ID: 5, Age: 35, Gender: Male, Ethnicity: White, Health Score: 80.10, Risk Factors: Hypertension Smoking 
Predicted Risk: 35.00%
...

Total Patients Simulated: 1000
```

## 📂 Detailed Explanation of the Diagrams
1. Architecture Diagram: Shows the overall system architecture, including the components like the Population Initialization, Simulation Engine, and Predictive Model.
2. Class Diagram: Illustrates the relationships between classes such as Patient, Policy, Simulation, and HealthPredictor.
3. Sequence Diagram: Visualizes the flow of the simulation process, from population initialization to generating the final report.
4. Use Case Diagram: Highlights the different user interactions, including running simulations and analyzing reports.
5. Output Diagram: Depicts the structure of the simulation output, showcasing patient details, predicted health risks, and overall simulation summary.





