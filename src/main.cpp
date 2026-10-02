#include <iostream>
#include "sitl-sensors/fuel-sensor.h"
#include "sitl-sensors/air-speed-sensor.h"
#include "event-bus/event-bus.h"
#include "fuel/fuel-service.h"
#include "sensor-health/sensor-health-service.h"


int main()
{
    FuelSensor fuelSensor;
    AirSpeedSensor airSpeedSensor;
    EventBus eventBus; 
    FuelService fuelService(eventBus); 
    SensorHealthService sensorHealthService(eventBus);

    bool running = true;

    while (running)
    {
        std::cout << "\n=============================\n";
        std::cout << " Aircraft Management System\n";
        std::cout << "=============================\n";
        std::cout << "1. Read Fuel Sensor\n";
        std::cout << "2. Read Airspeed Sensor\n";
        std::cout << "3. Show All Data\n";
        std::cout << "4. Exit\n";
        std::cout << "=============================\n";
        std::cout << "Select option: ";

        int choice;
        std::cin >> choice;

        switch (choice)
        {
            case 1:
                fuelSensor.GetData(50.0f, 100.0f);
                fuelSensor.PrintData();
                break;

            case 2:
                airSpeedSensor.GetData(120.0f, 150.0f);
                airSpeedSensor.PrintData();
                break;

            case 3:
                std::cout << "\n--- Fuel Data ---\n";
                fuelSensor.PrintData();

                std::cout << "\n--- Airspeed Data ---\n";
                airSpeedSensor.PrintData();
                break;

            case 4:
                running = false;
                std::cout << "Exiting...\n";
                break;

            default:
                std::cout << "Invalid option.\n";
                break;
        }
    }

    return 0;
}