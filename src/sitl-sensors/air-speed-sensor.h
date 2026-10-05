#pragma once

#include "sensor.h"
#include "event-bus/event-bus.h"

class AirSpeedSensor : public Sensor { 
public:
    // Sensors dont have subscriptions as they only output data
    AirSpeedSensor(EventBus& bus);
    int GetData() override;
    float GetAirSpeedData(float minimum, float maximum); 
    void PrintData() override;
private:
    float Air_Speed;
    float Maximum_Air_Speed_Change = 5.0;
    float Air_Speed_Variance = 0.03; // For the purposes of the simulation, 
                                     // this is how severaly the altitude fluctubates
    EventBus& bus; 
    float _Minimum_Airspeed; 
    float _Maximum_Airspeed; 
};
