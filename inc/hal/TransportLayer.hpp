#ifndef __TRANSPORTLAYER_HPP_
#define __TRANSPORTLAYER_HPP_
class TransportLayer {
    public :
      virtual void Init() = 0;
      virtual void Read(uint8_t length, uint8_t* data) = 0;
      virtual void Write() = 0;
};

#endif