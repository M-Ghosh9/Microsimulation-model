cmake_minimum_required(VERSION 3.16)
project(MicrosimulationModel)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add src and include directories
include_directories(include)
file(GLOB SOURCES "src/*.cpp")

# Create the executable
add_executable(microsimulation ${SOURCES})

# Link libraries for multithreading
find_package(Threads REQUIRED)
target_link_libraries(microsimulation PRIVATE Threads::Threads)

# Enable testing
enable_testing()
add_subdirectory(tests)
