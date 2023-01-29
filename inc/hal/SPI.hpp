#ifndef __SPI_HPP_
#define __SPI_HPP_
#include <stdint.h>
#include "TransportLayer.hpp"

class SPI : public TransportLayer{
    public:
    SPI() {
        Init();
    }
      void Init() {

      }
      void Write() {

      }
      void Read(uint8_t length, uint8_t* data) {
        data[0] = 1;
        data[1] = 2;
      }
};
#endif