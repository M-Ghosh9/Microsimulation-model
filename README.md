# Microsimulation-model for Healthcare Policy
A C++ application that simulates healthcare policy impacts on patient outcomes. 

## 📚 Project Overview
This project is a C++ application that simulates the impact of various healthcare policies on patient outcomes. It leverages C++20/23 features such as Concepts, Ranges, Smart Pointers, Vectorization and Multithreading to model the effects of healthcare interventions on patient health metrics. The project is run on Windows 11th Gen Intel(R) Core(TM) i5-1135G7 @ 2.40GHz 2.42 GHz, and NVDIA GeForce MX330 GPU. 

## 🛠️ Features
1. Multithreading & Vectorization: Parallel processing for scalability and faster simulations.
2. Modern C++: Utilizes Concepts, Ranges, and Smart Pointers for cleaner and efficient code.
3. Predictive Modeling: Includes a health predictor to assess disease risks based on patient attributes.
4. Simulation Reports: Generates detailed reports on the impact of healthcare policies.
5. Modular Design: Easily extendable and maintainable code structure for future enhancements.

## Architecture Diagram
![image](https://github.com/user-attachments/assets/6e8d1dc1-f366-4e27-96da-1c25c9d9d153)


## Class Diagram
![image](https://github.com/user-attachments/assets/68671b42-5e00-46af-a3b5-3e5ad76655d3)

## Sequence Diagram
![image](https://github.com/user-attachments/assets/5686a298-7268-4d9a-9c42-f44f3fd6baa8)

## Use Case Diagram
![image](https://github.com/user-attachments/assets/ea2a3252-a1de-4e03-809f-58668a20fc1f)

## Classification Report
```plaintext
Classification Report:
                 precision  recall   f1-score   support

    diabetes       0.25      0.22      0.23      4579
hypertension       0.26      0.22      0.24      4571
     obesity       0.26      0.22      0.24      4725
     smoking       0.25      0.22      0.23      4500
```
![classification](https://github.com/user-attachments/assets/7c03906b-6518-440d-a5c4-2d3ae7b0c7cd)

``` plaintext
   micro avg       0.25      0.22      0.24     18375
   macro avg       0.25      0.22      0.24     18375
weighted avg       0.25      0.22      0.24     18375
 samples avg       0.15      0.15      0.14     18375
``` 
![risk factors](https://github.com/user-attachments/assets/692410e2-0466-4f8f-be7f-f74e563b1170)
 ``` plaintext
Samples with no true labels: 6669
Risk factor distribution:
diabetes        22786
hypertension    22907
obesity         23120
smoking         23085
dtype: int64
```
## 📊 Dashboard for Users
Dash is running on 
``` plaintext
http://127.0.0.1:8050/
```

## Visualization
1. Age Distribution across the population
   ![age distribution](https://github.com/user-attachments/assets/a1e91eb9-5f47-43d8-a076-275ea7a38dc2)
2. Health Score Distribution across the population
   ![healthscore distribution](https://github.com/user-attachments/assets/80c31a93-bc04-49fc-8369-203264c26957)
3. Prevalence of Diabetes across Age Group and Gender
   ![diabetes by age grp and gender](https://github.com/user-attachments/assets/6117af8d-07c3-4dbe-888e-c7823b489d01)
4. Prevalence of Hypertension across Age Group and Gender
   ![hypertension by age grp and gender](https://github.com/user-attachments/assets/6c7fce30-1181-43e2-8c97-2b3ff78c4cba)
5. Prevalence of Obesity across Age Group and Gender
   ![obesity by age grp and gender](https://github.com/user-attachments/assets/f1e39023-43a8-4e3e-b98a-43ec2c65ad45)
7. Prevalence of Smoking across Age Group and Gender
   ![smoking by age grp and gender](https://github.com/user-attachments/assets/0bfa9963-6fd2-422b-8c1e-68552ff944d6)
8. Gender Distribution
![newplot](https://github.com/user-attachments/assets/deef1cf9-0d45-4046-a90a-a7e2307bdc60)
10. Proportion at Risk
![newplot (1)](https://github.com/user-attachments/assets/caab1226-4c6a-411a-b872-e268351fee3b)


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
├── python for visualization/
│   ├── main.py
│   ├── data_loading.py
│   ├── analysis.py
│   ├── predictive_model.py
│   ├── dashboard.py
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
./microsimulation.exe
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

## 📂 Detailed Explanation of the Diagrams
1. Architecture Diagram: Shows the overall system architecture, including the components like the Population Initialization, Simulation Engine, and Predictive Model.
2. Class Diagram: Illustrates the relationships between classes such as Patient, Policy, Simulation, and HealthPredictor.
3. Sequence Diagram: Visualizes the flow of the simulation process, from population initialization to generating the final report.
4. Use Case Diagram: Highlights the different user interactions, including running simulations and analyzing reports.
5. Output Diagram: Depicts the structure of the simulation output, showcasing patient details, predicted health risks, and overall simulation summary.





