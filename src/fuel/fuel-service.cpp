#include "fuel-service.h"
#include "events.h"


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
    if (this->Fuel_State == WARN) {
        if (this->Fuel_Level > this->Low_Fuel_Warning_Threshold) {
            bus.publish(LowFuelWarningCleared{});
        }
    }
}

void FuelService::RaiseLowFuelWarning() {
    if (this->Fuel_State == NORMAL) {
        if (this->Fuel_Level < this->Low_Fuel_Warning_Threshold) {
        bus.publish(LowFuelWarningRaised{}); 
        }
    }
}