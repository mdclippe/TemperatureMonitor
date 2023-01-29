#include "Controller.hpp"
#include <iostream>

void Controller::CheckTemperature() const
{
    auto temperature = _sensor.getTemperature().getValue();
    std::cout << temperature << " ; " << _min.getValue() << ";" << _max.getValue() << std::endl ;
    if (temperature < _min.getValue())
    {
        _heater.Heat();
    }
    if (temperature > _max.getValue())
    {
        _heater.Cool();
    }
    if (temperature >= _min.getValue() && 
             temperature <= _max.getValue() )
    {
        std::cout << "Turn off heater" << std::endl ;
           
        _heater.Off();
    }
}