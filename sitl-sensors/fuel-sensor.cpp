#include "fuel-sensor.h"
#include <stdlib.h> 
#include <iostream>

float FuelSensor::GetData(float minimum, float maximum) {
    // Generate a random fuel level between the minimum and maximum values
    fuelLevel = minimum + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (maximum - minimum)));
    return fuelLevel;
}

void FuelSensor::PrintData() {
    // Print the current fuel level
    std::cout << "Current Fuel Level: " << fuelLevel << std::endl;
}