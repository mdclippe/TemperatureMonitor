#include "Controller.hpp"
#include "Heater.hpp"
#include "ISensor.hpp"
#include "TemperatureSensor.hpp"
#include "SPI.hpp"
#include <iostream>

int main()
{
   SPI hal_spi_temp;

    TemperatureSensor temperature(hal_spi_temp);
    Heater heater;
    Controller monitor (temperature,heater);
    monitor.SetMinimumTemperature(10.0);
    monitor.SetMaximumTemperature(15.0);
    // should start this in a seperate thread
    while (true)
    {
        monitor.CheckTemperature();
        // add delay here
    }
}