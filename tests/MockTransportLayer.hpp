#include "gmock/gmock.h"  // Brings in gMock
#include "TransportLayer.hpp"
class MockTransportLayer : public TransportLayer
{
    public :
      MOCK_METHOD(void, Init, (), (override));
      MOCK_METHOD(void, Read, (uint8_t length, uint8_t* data), (override));
      MOCK_METHOD(void, Write, (), (override));
};