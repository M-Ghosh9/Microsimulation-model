#include "gtest/gtest.h"
#include "Patient.h"

TEST(PatientTest, HealthScoreUpdate) {
    Patient patient(1, "Test", 25);
    patient.setHealthScore(80);
    ASSERT_EQ(patient.getHealthScore(), 80);
}
