#ifndef __HEATER_H_
#define __HEATER_H_

#include <stdint.h>
#include <iostream>
class IHeater {
    public :
        virtual void Heat() = 0;
        virtual void Cool() = 0;
        virtual void Off() = 0;
};

class Heater : public IHeater 
{
    private:
        uint32_t _setting;
    public:
        Heater() { std::cout << "Heater constr "<< std::endl;};
        ~Heater() {};
        uint32_t GetSetting () { return _setting; };
        void Heat() {
                    // turn on Heater
            std::cout << "Turn on heater" << std::endl ;
        }
        void Cool() {
            std::cout << "Turn on cooler" << std::endl ;
        }
        void Off() {
            std::cout << "Turn off " << std::endl ;
        }
};

#endif