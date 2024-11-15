find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(tests test_patient.cpp test_simulation.cpp)
target_link_libraries(tests ${GTEST_LIBRARIES} pthread)
add_test(NAME MicrosimulationTests COMMAND tests)
