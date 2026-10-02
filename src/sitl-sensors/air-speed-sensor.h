#pragma once

#include "sensor.h"

class AirSpeedSensor : public Sensor { 
public:
    AirSpeedSensor();
    float GetData(float minimum, float maximum) override;
    void PrintData() override;
private:
    float airSpeed;
};
