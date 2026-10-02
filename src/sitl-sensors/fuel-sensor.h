#ifndef FUEL_SENSOR_H
#define FUEL_SENSOR_H

#include "sensor.h"

class FuelSensor : public Sensor {
public:
    FuelSensor();
    float GetData(float minimum, float maximum) override;
    void PrintData() override;
private:
    float fuelLevel;
};

#endif // FUEL_SENSOR_H