# Microsimulation-model for Healthcare Policy
A C++ application that simulates healthcare policy impacts on patient outcomes. 

## 📚 Project Overview
This project is a **C++ application** that simulates the impact of healthcare policies on patient outcomes. The simulation leverages **modern C++20/23 features** such as concepts, ranges, smart pointers, and multithreading to model the effects of different healthcare policies on patient health metrics.

### 🛠️ Features
- **Multithreading**: Parallel processing for scalability.
- **Modern C++**: Utilizes Concepts, Ranges, and Smart Pointers.
- **Simulation Reports**: Generates detailed reports on policy impacts.
- **Modular Design**: Easily extendable and maintainable code structure.

## 📂 Project Structure

```plaintext
microsimulation-model/
├── CMakeLists.txt
├── README.md
├── LICENSE
├── docs/
│   ├── architecture.png      # Architecture diagram
│   ├── class_diagram.png     # Class diagram
│   └── usage_guide.md        # Detailed usage guide
├── include/
│   ├── Patient.h
│   ├── Hospital.h
│   ├── Policy.h
│   ├── Treatment.h
│   ├── Simulation.h
│   └── ReportGenerator.h
├── src/
│   ├── main.cpp
│   ├── Patient.cpp
│   ├── Hospital.cpp
│   ├── Policy.cpp
│   ├── Treatment.cpp
│   ├── Simulation.cpp
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
    └── class_diagram.png

🚀 Getting Started
📦 Prerequisites
CMake (version 3.16+)
C++ Compiler (GCC, Clang, or MSVC)
Google Test (for unit testing)
⚙️ Installation
Clone the repository and build the project using CMake:
git clone https://github.com/M-Ghosh9/Microsimulation-model.git
cd Microsimulation-model
mkdir build
cd build
cmake ..
make

🏃‍♂️ Running the Simulation
To run the simulation:
./microsimulation

✅ Running Tests
To run unit tests:
./tests/tests

📊 Generating Reports
Use the provided script to generate reports:
./scripts/generate_report.sh


