#pragma once

#include "sensor.h"

class FuelSensor : public Sensor {
public:
    FuelSensor();
    float GetData(float minimum, float maximum) override;
    void PrintData() override;
private:
    float fuelLevel;
};
