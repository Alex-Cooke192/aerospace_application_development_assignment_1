cmake_minimum_required( VERSION 3.16 )

project( fuel_manager VERSION 1.0 )
project( fuel_manager LANGUAGES CXX )
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(fuel_management_system 
    src/main.cpp 
    src/sitl-sensors/fuel-sensor.cpp 
    src/sitl-sensors/air-speed-sensor.cpp
    src/event-bus/event-bus.cpp
    src/fuel-display/fuel-display-service.cpp
    src/fuel/fuel-service.cpp
    ) # assumes all cpp files are in a directory called `src`

target_include_directories(
    fuel_management_system
    PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

message(STATUS "C Compiler:   ${CMAKE_C_COMPILER}")
message(STATUS "C++ Compiler: ${CMAKE_CXX_COMPILER}")

target_compile_features( fuel_management_system PUBLIC cxx_std_26 ) # sets the C++ standard to C++26, as agreed in design report. 