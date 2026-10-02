cmake_minimum_required( VERSION 3.16 )

project( my_project VERSION 1.0 )

add_executable(fuel_management_system 
    src/main.cpp 
    src/sitl-sensors/fuel-sensor.cpp 
    src/sitl-sensors/air-speed-sensor.cpp
    ) # assumes all cpp files are in a directory called `src`
target_compile_features( fuel_management_system PUBLIC cxx_std_26 ) # sets the C++ standard to C++26, as agreed in design report. 