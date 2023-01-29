
#include "Temperature.hpp"
#include "TemperatureSensor.hpp"
#include "Heater.hpp"

class Controller {
    private:
       TemperatureSensor& _sensor;
       IHeater& _heater;
       Units _currentScale = CELSIUS;
       Temperature<double> _min, _max, _read;
    public:
        Controller(TemperatureSensor& temp_sensor, IHeater& heater) : 
            _sensor(temp_sensor),_heater(heater)
            {

            }
        ~Controller() {};
        void setTemperatureUnits(Units units) {
            // std::mutex;
        }
        void setScale(Units scale)
        {
            _currentScale = scale;
        }
        Units getScale(Units scale)
        {
            return _currentScale;
        }
        void CheckTemperature() const;
        // should we be able to change the min and max while running ?
        void SetMinimumTemperature(double min) {
            _min.setValue(min, _currentScale);
        };
        void SetMaximumTemperature(double max) {
            _max.setValue(max, _currentScale);
        };
};