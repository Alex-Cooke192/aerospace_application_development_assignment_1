#include "fuel-display-service.h"
#include "events.h"
#include <iostream>

FuelDisplayService::FuelDisplayService(EventBus& eventBus) : eventBus(eventBus) {
    this->Subscribe(); 
}

// Subscriptions to events
void FuelDisplayService::Subscribe() {
    eventBus.subscribe<FuelLevelChanged>(
        [this](const FuelLevelChanged& event)
        {
            this->PrintFuelLevelChanged(event.New_Fuel_Level);
        }
    );
    
    eventBus.subscribe<LowFuelWarningRaised>(
        [this](const LowFuelWarningRaised& event)
        {
            this->PrintLowFuelWarning(event.fuelState); 
        }
    );

    eventBus.subscribe<LowFuelWarningCleared>(
        [this](const LowFuelWarningCleared& event)
        {
            this->PrintLowFuelClear(event.fuelState);
        }
    );

    eventBus.subscribe<FuelConsumptionChanged>(
        [this](const FuelConsumptionChanged& event)
        {
            this->PrintFuelConsumptionChanged(event.New_Fuel_Consumption);
        }
    );

    eventBus.subscribe<RangeChanged>(
        [this](const RangeChanged& event)
        {
            this->PrintRangeChanged(event.New_Range);
        }
    );

};

void PrintFuelLevelChanged(float New_Fuel_Level) {
    std::cout << "Fuel Level Changed: " << std::endl; 
    std::cout << "Original: " << std::to_string(Fuel_Level) << std::endl;
    std::cout << "New:" << std::to_string(New_Fuel_Level) << std::endl; 
}

void PrintFuelConsumptionChanged(float New_Fuel_Consumption) {
    std::cout << "Fuel Consumption Changed: " << std::endl; 
    std::cout << "Original: " << std::to_string(Fuel_Consumption) << std::endl;
    std::cout << "New:" << std::to_string(New_Fuel_Consumption) << std::endl; 
}

void PrintRangeChanged(float New_Range) {
    std::cout << "Fuel Consumption Changed: " << std::endl; 
    std::cout << "Original: " << std::to_string(Range) << std::endl;
    std::cout << "New:" << std::to_string(New_Range) << std::endl; 
}

void PrintLowFuelWarning() {
    std::cout << "WARNING: FUEL LOW" << std::endl;
    std::cout << "Fuel level: " << Fuel_Level << std::endl; 
}

void PrintLowFuelClear() {
    std::cout << "WARNING CLEARED: FUEL NORMAL" << std::endl; 
    std::cout << "Fuel level: " << Fuel_Level << std::endl; 
}