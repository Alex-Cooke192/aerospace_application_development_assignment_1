#include "fuel-service.h"
#include "events.h"
#include "fuel-state.h"

FuelService::FuelService(EventBus& bus) : bus(bus) {
    this->Subscribe();
}

// Subscriptions to other services
void FuelService::Subscribe() { 
    // Listen for new sensor outputs from the sensors
    bus.subscribe<NewFuelLevelSensorOutput>(
        [this](const NewFuelLevelSensorOutput& event)
        {
            this->UpdateFuelLevel(event.Output_Fuel_Level);
            this->UpdateFuelConsumption(event.Output_Fuel_Consumption); 
        }
    );
}

void FuelService::UpdateFuelLevel(float New_Fuel_Level) {
    if (this->Fuel_Level != New_Fuel_Level) {
        bus.publish(FuelLevelChanged{New_Fuel_Level}); 
        this->Fuel_Level = New_Fuel_Level; 
        this->UpdateFuelRange(New_Fuel_Level);
    }
} 

void FuelService::UpdateFuelConsumption(float New_Fuel_Consumption) {
    if (this->Fuel_Consumption != New_Fuel_Consumption) {
        bus.publish(FuelConsumptionChanged{New_Fuel_Consumption}); 
        this->Fuel_Consumption = New_Fuel_Consumption; 
    }
}

void FuelService::UpdateFuelRange(float New_Fuel_Level) {
    float New_Range = New_Fuel_Level*Fuel_Efficiency; 
    this->Fuel_Range = New_Range; 
    bus.publish(FuelRangeChanged{New_Range}); 
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