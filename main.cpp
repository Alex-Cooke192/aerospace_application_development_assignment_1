#include <iostream>
#include "sitl-sensors/fuel-sensor.cpp"
#include "sitl-sensors/air-speed-sensor.cpp"

int main() {   
    FuelSensor fuelSensor;
    float minimumFuelLevel = 0.0f; // Minimum fuel level
    float maximumFuelLevel = 100.0f; // Maximum fuel level

    fuelSensor.GetData(minimumFuelLevel, maximumFuelLevel);
    fuelSensor.PrintData();

    AirSpeedSensor airSpeedSensor;
    float minimumAirSpeed = 0.0f; // Minimum air speed
    float maximumAirSpeed = 300.0f; // Maximum air speed
    
    airSpeedSensor.GetData(minimumAirSpeed, maximumAirSpeed);
    airSpeedSensor.PrintData();

    return 0;  
}

