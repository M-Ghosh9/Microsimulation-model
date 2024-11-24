# Microsimulation-model for Healthcare Policy
A C++ and Python-based application simulating the impact of healthcare policies on patient outcomes. This project leverages modern C++ (C++20/23) features and Python for predictive modeling and data visualization, providing stakeholders with actionable insights. 

## 📚 Project Overview
The microsimulation model evaluates the impact of healthcare policies, considering patient attributes such as age, gender, and risk factors. It uses:
1. Modern C++ features like multithreading, vectorization, and smart pointers for fast, scalable simulations.
2. Predictive modeling and dashboards to support data-driven policy-making decisions.

The model is designed for Windows 11 running on:
1. CPU: 11th Gen Intel(R) Core(TM) i5-1135G7 @ 2.40GHz.
2. GPU: NVIDIA GeForce MX330.

## 🛠️ Features
1. Scalable Simulations: Supports parallel processing and vectorization for large-scale simulations.
2. Predictive Modeling: Models health risks based on patient attributes using Python ML tools.
3. Interactive Visualizations: Dashboards for exploring health metrics, risk factors, and policy outcomes.
4. Detailed Reporting: Generates patient-level data, population summaries, and policy impact metrics.
5. Modular Design: Extensible C++ and Python architecture for easy enhancements.

## Architecture Diagram
![image](https://github.com/user-attachments/assets/6e8d1dc1-f366-4e27-96da-1c25c9d9d153)


## Class Diagram
![image](https://github.com/user-attachments/assets/68671b42-5e00-46af-a3b5-3e5ad76655d3)

## Sequence Diagram
![image](https://github.com/user-attachments/assets/5686a298-7268-4d9a-9c42-f44f3fd6baa8)

## Use Case Diagram
![image](https://github.com/user-attachments/assets/ea2a3252-a1de-4e03-809f-58668a20fc1f)

## Overall Synthetic Population Report: 
 ``` plaintext
Total population size: 100,000

Risk factor distribution:
diabetes        22786
hypertension    22907
obesity         23120
smoking         23085

Population Metrics Report:
Average Health Score: 81.70%
Proportion At Risk: 66.67%
Proportion with Diabetes: 24.88%
Proportion with Hypertension: 25.03%
Proportion with Obesity: 23.12%
Proportion with Smoking:  23.08%
```
![risk factors](https://github.com/user-attachments/assets/692410e2-0466-4f8f-be7f-f74e563b1170)

```plaintext
Classification Report:
                 precision  recall   f1-score   support

    diabetes       0.25      0.22      0.23      4579
hypertension       0.26      0.22      0.24      4571
     obesity       0.26      0.22      0.24      4725
     smoking       0.25      0.22      0.23      4500
```
![classification](https://github.com/user-attachments/assets/7c03906b-6518-440d-a5c4-2d3ae7b0c7cd)

 
## 📊 Dashboard for Users
Dash is running on 
``` plaintext
http://127.0.0.1:8050/
``` 

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
│   ├── *.h                   # Header files for core classes
├── src/
│   ├── *.cpp                 # Implementation of core classes
├── python for visualization/
│   ├── *.py                  # Python scripts for analysis and dashboards
├── tests/
│   ├── *.cpp                 # Unit tests
│   └── CMakeLists.txt
├── data/
│   └── patients_data.csv      # Synthetic patient data
├── scripts/
│   ├── run_simulation.sh      # Script to run simulations
│   └── generate_report.sh     # Script to generate reports
└── images/
    ├── *.png                  # Diagrams and visualizations
``` 

## 🚀 Getting Started
📦 Prerequisites
```plaintext
C++ Tools:
CMake (version 3.16+)
GCC, Clang, or MSVC compiler

Python Tools:
Python 3.8+
Libraries: numpy, pandas, matplotlib, seaborn, scikit-learn, dash
```

## ⚙️ Installation
1. Clone the repository and build the project using CMake:
```plaintext
git clone https://github.com/M-Ghosh9/Microsimulation-model.git
cd Microsimulation-model
```
2. Build the C++ application
```plaintext
mkdir build
cd build
cmake ..
make
```
3. Install python dependencies
```plaintext
pip install -r requirements.txt
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
## Run the Dashboard
``` plaintext
cd python\ for\ visualization/
python dashboard.py
```
Open the dashboard in your browser at 
``` plaintext
http://127.0.0.1:8050.
```
## Visualization

1.  Health Score Distribution across the population
   ![healthscore distribution](https://github.com/user-attachments/assets/80c31a93-bc04-49fc-8369-203264c26957)
2. Prevalence of Diabetes across Age Group and Gender
   ![diabetes by age grp and gender](https://github.com/user-attachments/assets/6117af8d-07c3-4dbe-888e-c7823b489d01)
3. Prevalence of Hypertension across Age Group and Gender
   ![hypertension by age grp and gender](https://github.com/user-attachments/assets/6c7fce30-1181-43e2-8c97-2b3ff78c4cba)
4. Prevalence of Obesity across Age Group and Gender
   ![obesity by age grp and gender](https://github.com/user-attachments/assets/f1e39023-43a8-4e3e-b98a-43ec2c65ad45)
5. Prevalence of Smoking across Age Group and Gender
   ![smoking by age grp and gender](https://github.com/user-attachments/assets/0bfa9963-6fd2-422b-8c1e-68552ff944d6)

## Actions for Policymakers
Focus on high-risk groups (health scores <60).
Promote interventions targeting prevalent risk factors.





