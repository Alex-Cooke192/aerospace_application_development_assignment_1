#pragma once

#include "sensor.h"
#include "event-bus/event-bus.h"

class FuelSensor : public Sensor {
public:
    FuelSensor(EventBus& bus);
    int GetData() override;

    float GetFuelLevelData(float minimum, float maximum); 
    float GetFuelConsumptionData(float minimum, float maximum);
    void PrintData() override;
private:
    float fuelLevel;
    EventBus& bus; 
    float _Fuel_Level_Minimum = 0.0; 
    float _Fuel_Level_Maximum = 100.0; 
    float _Fuel_Consumption_Minimum = 0.0; // Kg per second
    float _Fuel_Consumption_Maximum = 10.0; // Kg per second 
};
