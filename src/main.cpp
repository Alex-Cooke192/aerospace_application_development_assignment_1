#include <iostream>
#include <thread>

#include "sitl-sensors/fuel-sensor.h"
#include "sitl-sensors/air-speed-sensor.h"
#include "event-bus/event-bus.h"
#include "fuel/fuel-service.h"
#include "sensor-health/sensor-health-service.h"
#include "event-bus/events.h"
#include "fuel-display/fuel-display-service.h"
#include "aircraft-configuration.h"



int main()
{
    EventBus eventBus; 
    FuelSensor fuelSensor(eventBus, aircraftConfig);
    AirSpeedSensor airSpeedSensor(eventBus);
    FuelService fuelService(eventBus, aircraftConfig); 
    SensorHealthService sensorHealthService(eventBus);
    FuelDisplayService fuelDisplay(eventBus); 

    bool running = true;

    std::thread sensorThread([&]() {
        while (running) {
            fuelSensor.GetData();
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    });

    while (running) {
        std::string command;
        std::getline(std::cin, command);

        if (command == "quit") {
            running = false;
        }
    }
}