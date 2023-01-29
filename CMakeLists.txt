cmake_minimum_required(VERSION 3.14)
project(temperature_monitor)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set (SOURCES
  ${PROJECT_SOURCE_DIR}/src/main.cpp
  ${PROJECT_SOURCE_DIR}/src/Temperature.cpp
  ${PROJECT_SOURCE_DIR}/src/Heater.cpp
  ${PROJECT_SOURCE_DIR}/src/TemperatureSensor.cpp
  ${PROJECT_SOURCE_DIR}/src/Controller.cpp
  ${PROJECT_SOURCE_DIR}/src/hal/SPI.cpp

)
set (INCLUDES
	${PROJECT_SOURCE_DIR}/inc
  ${PROJECT_SOURCE_DIR}/inc/hal
)
add_executable(temperature_monitor ${SOURCES})

# target_sources(temperature_monitor PRIVATE ${SOURCES})
target_include_directories(temperature_monitor PRIVATE ${INCLUDES})

enable_testing()

add_executable(
  Temperature_test
  tests/Temperature_test.cpp
  tests/SystemTest.cpp
  src/Controller.cpp
)
target_include_directories(Temperature_test PRIVATE ${INCLUDES})
target_link_libraries(
  Temperature_test
  GTest::gtest_main
  gmock_main
)


include(GoogleTest)
gtest_discover_tests(Temperature_test)