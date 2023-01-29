#include "gmock/gmock.h"  // Brings in gMock
#include "Heater.hpp"
class MockHeater : public IHeater
{
    public :
      MOCK_METHOD(void, Heat, (), (override));
      MOCK_METHOD(void, Cool, (), (override));
      MOCK_METHOD(void, Off, (), (override));
};