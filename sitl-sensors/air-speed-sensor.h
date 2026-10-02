#ifndef AIR_SPEED_SENSOR_H
#define AIR_SPEED_SENSOR_H

#include "sensor.h"

class AirSpeedSensor : public Sensor { 
public:
    AirSpeedSensor();
    float GetData(float minimum, float maximum) override;
    void PrintData() override;
private:
    float airSpeed;
};

#endif // AIR_SPEED_SENSOR_H