#include "sensor.h"
#include <stdlib.h> 

class FuelSensor : public Sensor {
public:
    FuelSensor();
    float GetData() override;
    void PrintData() override;
private:
    float fuelLevel;
}

float FuelSensor::GetData(float minimum, float maximum) {
    // Generate a random fuel level between the minimum and maximum values
    fuelLevel = minimum + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (maximum - minimum)));
    return fuelLevel;
}

void FuelSensor::PrintData() {
    // Print the current fuel level
    std::cout << "Current Fuel Level: " << fuelLevel << std::endl;
}