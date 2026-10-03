#include "fuel-service.h"
#include "events.h"
#include "fuel-state.h"

FuelService::FuelService(EventBus& bus) : bus(bus) {
    this->Subscribe();
}

void FuelService::Subscribe() {
    // Subscriptions to other services
    bus.subscribe<FuelLevelChanged>(
        [this](const FuelLevelChanged& event)
        {
            this->UpdateFuelLevel(event.New_Fuel_Level);
        }
    );

    bus.subscribe<FuelConsumptionChanged>(
        [this](const FuelConsumptionChanged& event)
        {
            this->UpdateFuelConsumption(event.New_Fuel_Consumption);
        }
    );
}



void FuelService::UpdateFuelLevel(float New_Fuel_Level) {
    if (this->Fuel_Level != New_Fuel_Level) {
        bus.publish(FuelLevelChanged{New_Fuel_Level}); 
        this->Fuel_Level = New_Fuel_Level; 
    }
} 

void FuelService::UpdateFuelConsumption(float New_Fuel_Consumption) {
    if (this->Fuel_Consumption != New_Fuel_Consumption) {
        bus.publish(FuelConsumptionChanged{New_Fuel_Consumption}); 
        this->Fuel_Consumption = New_Fuel_Consumption; 
    }
}

void FuelService::UpdateRange(float New_Fuel_Level) {
    if (this->Fuel_Level != New_Fuel_Level) {
        
    }
}

void FuelService::ClearLowFuelWarning() {
    if (this->fuelState == FuelState::WARN) {
        if (this->Fuel_Level > this->Low_Fuel_Warning_Threshold) {
            bus.publish(LowFuelWarningCleared{});
            this->fuelState == FuelState::NORMAL;
        }
    }
}

void FuelService::RaiseLowFuelWarning() {
    if (this->fuelState == FuelState::NORMAL) {
        if (this->Fuel_Level < this->Low_Fuel_Warning_Threshold) {
            bus.publish(LowFuelWarningRaised{fuelState}); 
            this->fuelState == FuelState::WARN; 
        }
    }
}