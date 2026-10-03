#include <stdlib.h> 
#include <iostream>
#include "air-speed-sensor.h"
#include "event-bus/event-bus.h"

AirSpeedSensor::AirSpeedSensor(EventBus& bus) : bus(bus) {
}

int AirSpeedSensor::GetData() {
    GetAirSpeed(this->_Minimum_Airspeed, this->_Maximum_Airspeed); 
    return 0; 
};

float AirSpeedSensor::GetAirSpeed(float minimum, float maximum) {
     // Generate a random air speed between the minimum and maximum values
    float airSpeed = minimum + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (maximum - minimum)));
    return airSpeed;
}

void AirSpeedSensor::PrintData() {
    // Print the current air speed
    std::cout << "Current Air Speed: " << airSpeed << std::endl;
}