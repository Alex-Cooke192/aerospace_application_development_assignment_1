#include <iostream>
#include "sitl-sensors/fuel-sensor.h"
#include "sitl-sensors/air-speed-sensor.h"

int main() {   
    FuelSensor fuelSensor;
    float minimumFuelLevel = 0.0f; // Minimum fuel level
    float maximumFuelLevel = 100.0f; // Maximum fuel level

    AirSpeedSensor airSpeedSensor;
    float minimumAirSpeed = 0.0f; // Minimum air speed
    float maximumAirSpeed = 300.0f; // Maximum air speed

    for (int i=0; i<10; i++) {
        fuelSensor.GetData(minimumFuelLevel, maximumFuelLevel);
        fuelSensor.PrintData();
    
        airSpeedSensor.GetData(minimumAirSpeed, maximumAirSpeed);
        airSpeedSensor.PrintData();
    }
    return 0;  
}

