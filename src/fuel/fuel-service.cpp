#include "fuel-service.h"
#include "event-bus/events.h"
#include "fuel-state.h"

FuelService::FuelService(EventBus& bus) : bus(bus) {
    this->Subscribe();
}

// Subscriptions to other services
void FuelService::Subscribe() { 
    // Listen for new sensor outputs from the sensors
    bus.subscribe<NewFuelSensorOutput>(
        [this](const NewFuelSensorOutput& event)
        {
            this->CheckFuelLevelChanged(event.Output_Fuel_Level);
            this->CheckFuelConsumptionChanged(event.Output_Fuel_Consumption); 
        }
    );
}

// -----------------------------------------------------------------
// Fuel Level Functions

void FuelService::CheckFuelLevelChanged(float New_Fuel_Level) {
    if (this->Fuel_Level != New_Fuel_Level) {
        UpdateFuelLevel(New_Fuel_Level);
    }
}

void FuelService::UpdateFuelLevel(float New_Fuel_Level) {
    // Store old fuel level for publishing
    float Original_Fuel_Level = this->Fuel_Level;
    // Update fuel level
    this->Fuel_Level = New_Fuel_Level; 
    // Publish that the change has happened
    bus.publish(FuelLevelChanged{Original_Fuel_Level, New_Fuel_Level}); 
    // Update new range accordingly
    this->UpdateFuelRange(New_Fuel_Level);
    // Check low fuel transitions
    CheckLowFuelWarning(); 
    CheckLowFuelClear(); 
} 

// ----------------------------------------------------------------------------------------
// Fuel Range Function

void FuelService::UpdateFuelRange(float New_Fuel_Level) {
    float New_Range = New_Fuel_Level*Fuel_Efficiency; 
    this->Fuel_Range = New_Range; 
    bus.publish(FuelRangeChanged{this->Fuel_Range, New_Range}); 
}

// ----------------------------------------------------------------------------------------
// Fuel Consumptions Function 

void FuelService::CheckFuelConsumptionChanged(float New_Fuel_Consumption) {
    if (this->Fuel_Consumption != New_Fuel_Consumption) {
        UpdateFuelConsumption(New_Fuel_Consumption); 
    }
}

void FuelService::UpdateFuelConsumption(float New_Fuel_Consumption) {
    // Store original value for publishing 
    float Original_Fuel_Consumption = this->Fuel_Consumption;
    // Update Fuel Consumption
    this->Fuel_Consumption = New_Fuel_Consumption; 
    // Publish result
    bus.publish(FuelConsumptionChanged{Original_Fuel_Consumption, New_Fuel_Consumption}); 
}


// -----------------------------------------------------------------------------------------
// Low fuel warnning checkers/transitions

void FuelService::CheckLowFuelWarning() {
    if (this->_Fuel_State == FuelState::NORMAL) {
        if (this->Fuel_Level < this->Low_Fuel_Warning_Threshold) {
            this->_Fuel_State = FuelState::WARN;
            RaiseLowFuelWarning(); 
        }
    }
}

void FuelService::RaiseLowFuelWarning() {
    bus.publish(LowFuelWarningRaised{FuelState::WARN, this->Fuel_Level}); 
}

// -------------------------------------------------------------------------------------------

void FuelService::CheckLowFuelClear() {
    if (this->_Fuel_State == FuelState::WARN) {
        if (this->Fuel_Level > this->Low_Fuel_Warning_Threshold) {
            this->_Fuel_State = FuelState::NORMAL;
            RaiseLowFuelWarningCleared(); 
        }
    }
}

void FuelService::RaiseLowFuelWarningCleared() {
    bus.publish(LowFuelWarningCleared{FuelState::NORMAL, this->Fuel_Level});
}