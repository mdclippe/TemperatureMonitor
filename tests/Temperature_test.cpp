#include <gtest/gtest.h>
#include "Temperature.hpp"

// use temperature fixture

class TemperatureTest : public ::testing::Test {
     protected:
        void SetUp() override {
            t1.setValue(0.0, CELSIUS);
            t2.setValue(32.0, FAHRENHEIT);
            t3.setValue(273.15, KELVIN);
        }
        Temperature<double> t1;
        Temperature<double> t2;
        Temperature<double> t3;
};

TEST_F(TemperatureTest, Celsius_zero_to_other) {
   EXPECT_DOUBLE_EQ(t1.getValue(CELSIUS),0.0);
   EXPECT_DOUBLE_EQ(t1.getValue(FAHRENHEIT),32);
   EXPECT_DOUBLE_EQ(t1.getValue(KELVIN),273.15);
}

TEST_F(TemperatureTest, Fahrenheit_zero_to_other) {
    EXPECT_DOUBLE_EQ(t1.getValue(CELSIUS),0.0);
   EXPECT_DOUBLE_EQ(t1.getValue(FAHRENHEIT),32);
   EXPECT_DOUBLE_EQ(t1.getValue(KELVIN),273.15);
}

TEST_F(TemperatureTest, Kelvin_zero_to_other) {
   EXPECT_DOUBLE_EQ(t1.getValue(CELSIUS),0.0);
   EXPECT_DOUBLE_EQ(t1.getValue(FAHRENHEIT),32);
   EXPECT_DOUBLE_EQ(t1.getValue(KELVIN),273.15);
}