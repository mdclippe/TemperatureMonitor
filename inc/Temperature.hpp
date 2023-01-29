
#ifndef __TEMPERATUR_HPP_
#define __TEMPERATUR_HPP_
#include <stdlib.h>
#include <math.h>

// class to store temperature values and conversions
enum Units {
    CELSIUS,
    FAHRENHEIT,
    KELVIN
};

template <class T>
class Temperature {
    private :
        // only store the absolute_value in Kelvin
        T _absolute_value_Kelvin;
    public :
        // constructor
        Temperature() {};
        Temperature(T value) : _absolute_value_Kelvin(value) {}
        T getValue(Units outputUnits = KELVIN) const 
        {
            return (Convert(_absolute_value_Kelvin, KELVIN, outputUnits));
        }
        // 
        void setValue(T value,Units inputUnits, Units outputUnits = KELVIN)
        {
            _absolute_value_Kelvin = Convert(value, inputUnits, outputUnits);
        }

        bool operator==(const Temperature<T>& other) const
        {
            return this->getValue() == other.getValue();
        }
        
        bool operator<(const Temperature<T>& other) const
        {
            return this->getValue() < other.getValue();
        }

        bool operator>(const Temperature<T>& other) const
        {
            return this->getValue() > other.getValue();
        }

          bool operator<=(const Temperature<T>& other) const
        {
            return this->getValue() <= other.getValue();
        }

        bool operator>=(const Temperature<T>& other) const
        {
            return this->getValue() >= other.getValue();
        }

        static T Convert(T const value, 
                        Units inputUnits,
                        Units outputUnits)
        {
            // no need to perform conversion
            if (inputUnits == outputUnits) return value;    
            switch (inputUnits)
            {
                case CELSIUS :
                {
                    switch (outputUnits)
                    {
                        case FAHRENHEIT :
                        {
                            return ((value * (9.0/5.0)) + 32);
                        }
                        case KELVIN :
                        {
                            return (value + 273.15);
                        }
                        default :
                        {
                            break;
                        }
                    }
                    break;
                }
                case FAHRENHEIT :
                {
                    switch (outputUnits)
                    {
                        case CELSIUS :
                        {
                            return ((value - 32) * (5.0/9.0));
                        }
                        case KELVIN :
                        {
                            // first convert back to celsius
                            return Convert(value, FAHRENHEIT, CELSIUS) + 273.15;
                        }
                        default :
                        {
                            break;
                        }
                    }

                    break;
                }
                case KELVIN :
                {
                    switch (outputUnits)
                    {
                        case CELSIUS :
                        {
                            return (value - 273.15);
                        }
                        case FAHRENHEIT :
                        {
                            return Convert(value - 273.15, CELSIUS, FAHRENHEIT);
                        }
                        default :
                        {
                            break;
                        }
                    }
                    break;
                }
                default :
                {
                    break;
                }

            }
            // if nothing found, return the value as is
            return value;
        }
};
#endif