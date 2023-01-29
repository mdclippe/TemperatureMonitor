#include "MockTransportLayer.hpp"
#include "MockHeater.hpp"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "TemperatureSensor.hpp"
#include "Heater.hpp"
#include "Controller.hpp"
#include "Temperature.hpp"

using ::testing::AtLeast;                         
using ::testing::Exactly;    
using ::testing::Return;
using ::testing::Mock;
using ::testing::_;
using ::testing::Invoke;
using ::testing::NiceMock;

TEST(SystemTest, CoolerOn) {
  MockTransportLayer spiMock;                         
  TemperatureSensor sensor(spiMock);  
    
    EXPECT_CALL(spiMock, Read(_,_)).WillOnce(Invoke(
            [=](uint8_t len, uint8_t* data){
               data[0] = 0x14;
               data[1] = 0x00;
            }));

    NiceMock<MockHeater> heater;
         EXPECT_CALL(heater, Cool())
      .Times(Exactly(1));
    Controller monitor (sensor,heater);
    Temperature<double> temp;
    monitor.SetMinimumTemperature(10.0);
    monitor.SetMaximumTemperature(15.0);
    monitor.CheckTemperature();
}

TEST(SystemTest, HeaterOn) {
  MockTransportLayer spiMock;                         
  TemperatureSensor sensor(spiMock);  
    
    EXPECT_CALL(spiMock, Read(_,_)).WillOnce(Invoke(
            [=](uint8_t len, uint8_t* data){
               data[0] = 0x09;
               data[1] = 0x00;
            }));

    NiceMock<MockHeater> heater;
        
     EXPECT_CALL(heater, Heat())
      .Times(Exactly(1));
    Controller monitor (sensor,heater);
    Temperature<double> temp;
    monitor.SetMinimumTemperature(10.0);
    monitor.SetMaximumTemperature(15.0);
    monitor.CheckTemperature();
}

TEST(SystemTest, HeaterOff) {
  MockTransportLayer spiMock;                         
  TemperatureSensor sensor(spiMock);  
    
    EXPECT_CALL(spiMock, Read(_,_)).WillOnce(Invoke(
            [=](uint8_t len, uint8_t* data){
               data[0] = 0x0F;
               data[1] = 0x00;
            }));

    NiceMock<MockHeater> heater;
        
     EXPECT_CALL(heater, Off())
      .Times(Exactly(1));
    Controller monitor (sensor,heater);
    Temperature<double> temp;
    monitor.SetMinimumTemperature(10.0);
    monitor.SetMaximumTemperature(15.0);
    monitor.CheckTemperature();
}