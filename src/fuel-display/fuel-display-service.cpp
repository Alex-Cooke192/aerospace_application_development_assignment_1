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
            this->PrintFuelLevelChanged(event.Original_Fuel_Level, event.New_Fuel_Level);
        }
    );
    
    eventBus.subscribe<LowFuelWarningRaised>(
        [this](const LowFuelWarningRaised& event)
        {
            this->PrintLowFuelWarning(event.Fuel_Level); 
        }
    );

    eventBus.subscribe<LowFuelWarningCleared>(
        [this](const LowFuelWarningCleared& event)
        {
            this->PrintLowFuelClear(event.Fuel_Level);
        }
    );

    eventBus.subscribe<FuelConsumptionChanged>(
        [this](const FuelConsumptionChanged& event)
        {
            this->PrintFuelConsumptionChanged(event.Original_Fuel_Consumption, event.New_Fuel_Consumption);
        }
    );

    eventBus.subscribe<FuelRangeChanged>(
        [this](const FuelRangeChanged& event)
        {
            this->PrintRangeChanged(event.Original_Fuel_Range, event.New_Fuel_Range);
        }
    );

};

void PrintFuelLevelChanged(float Original_Fuel_Level, float New_Fuel_Level) {
    std::cout << "Fuel Level Changed: " << std::endl; 
    std::cout << "Original: " << std::to_string(Original_Fuel_Level) << std::endl;
    std::cout << "New:" << std::to_string(New_Fuel_Level) << std::endl; 
}

void PrintFuelConsumptionChanged(float Original_Fuel_Consumption, float New_Fuel_Consumption) {
    std::cout << "Fuel Consumption Changed: " << std::endl; 
    std::cout << "Original: " << std::to_string(Original_Fuel_Consumption) << std::endl;
    std::cout << "New:" << std::to_string(New_Fuel_Consumption) << std::endl; 
}

void PrintRangeChanged(float Original_Range, float New_Range) {
    std::cout << "Fuel Consumption Changed: " << std::endl; 
    std::cout << "Original: " << std::to_string(Original_Range) << std::endl;
    std::cout << "New:" << std::to_string(New_Range) << std::endl; 
}

void PrintLowFuelWarning(float Fuel_Level) {
    std::cout << "WARNING: FUEL LOW" << std::endl;
    std::cout << "Fuel level: " << Fuel_Level << std::endl; 
}

void PrintLowFuelClear(float Fuel_Level) {
    std::cout << "WARNING CLEARED: FUEL NORMAL" << std::endl; 
    std::cout << "Fuel level: " << Fuel_Level << std::endl; 
}