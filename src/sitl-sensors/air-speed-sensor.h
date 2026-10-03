#pragma once

#include "sensor.h"
#include "event-bus/event-bus.h"

class AirSpeedSensor : public Sensor { 
public:
    // Sensors dont have subscriptions as they only output data
    AirSpeedSensor(EventBus& bus);
    int GetData() override;
    float GetAirSpeed(float minimum, float maximum); 
    void PrintData() override;
private:
    float airSpeed;
    EventBus& bus; 
    float _Minimum_Airspeed; 
    float _Maximum_Airspeed; 
};
