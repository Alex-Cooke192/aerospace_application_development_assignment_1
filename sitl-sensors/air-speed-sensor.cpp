#include <stdlib.h> 
#include <iostream>
#include "air-speed-sensor.h"

float AirSpeedSensor::GetData(float minimum, float maximum) {
    // Generate a random air speed between the minimum and maximum values
    airSpeed = minimum + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (maximum - minimum)));
    return airSpeed;
};

void AirSpeedSensor::PrintData() {
    // Print the current air speed
    std::cout << "Current Air Speed: " << airSpeed << std::endl;
}