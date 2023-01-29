#ifndef __TEMPERATURESENSOR_HPP_
#define __TEMPERATURESENSOR_HPP_
#include "ISensor.hpp"
#include "SPI.hpp"
#include "Temperature.hpp"
#include <stdint.h>
#include <thread>
#include <mutex>
#include <iostream>

// template<class TTransport>
class TemperatureSensor : public ISensor {
    // add communicationprotocol for accessing the actual sensor
    private:
        std::mutex _temp_mutex;
        TransportLayer& _hal_transport;
        Temperature<double> _latestTemperature;
        double convert_raw_to_temp(uint8_t* data) 
        {
            // assume value is in Celcius and LSB
            // use just data as is
            double ret = ((data[1] << 8) + data[0]);
            std::cout << "temp val : " << ret << std::endl;
            return ret;
            
        }; 
    public:
        TemperatureSensor(TransportLayer& hal_transport) : _hal_transport(hal_transport) 
        {

        };

        // use thread mutex here
        Temperature<double>& getTemperature() {
            std::lock_guard<std::mutex> lk(_temp_mutex);
            // read from the actual device

            uint8_t data[2] = {};
            _hal_transport.Read(2, data);
            _latestTemperature.setValue(convert_raw_to_temp(data), CELSIUS);
            return _latestTemperature;
        };
};

#endif