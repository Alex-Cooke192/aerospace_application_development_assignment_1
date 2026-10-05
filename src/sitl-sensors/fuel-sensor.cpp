#include "fuel-sensor.h"
#include "event-bus/events.h"
#include <stdlib.h> 
#include <iostream>

FuelSensor::FuelSensor(EventBus& bus, AircraftConfiguration aircraftConfig) : bus(bus) {
    this->_Fuel_Consumption_Maximum = aircraftConfig.fuelMetrics.fuel_consumption_maximum;
    this->_Fuel_Consumption_Minimum = aircraftConfig.fuelMetrics.fuel_consumption_minimum;
    this->_Fuel_Level_Maximum = aircraftConfig.fuelMetrics.fuel_capacity;
    this->_Fuel_Level_Minimum = 0.0;
}

int FuelSensor::GetData() {
    GetFuelLevelData(this->_Fuel_Level_Minimum, this->_Fuel_Level_Maximum); 
    GetFuelConsumptionData(this->_Fuel_Consumption_Minimum, this->_Fuel_Consumption_Maximum); 
    return 0;
}


float FuelSensor::GetFuelLevelData(float minimum, float maximum) {
    // Generate a random fuel level between the minimum and maximum values
    float fuelLevel = minimum + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (maximum - minimum)));
    bus.publish(NewFuelLevelSensorOutput{fuelLevel});
    return fuelLevel;
}

float FuelSensor::GetFuelConsumptionData(float minimum, float maximum) {
    float fuelConsumption = minimum + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (maximum - minimum)));
    bus.publish(NewFuelConsumptionSensorOutput{fuelConsumption});
    return fuelConsumption; 
}

void FuelSensor::PrintData() {
    // Print the current fuel level
    std::cout << "Current Fuel Level: " << fuelLevel << std::endl;
}