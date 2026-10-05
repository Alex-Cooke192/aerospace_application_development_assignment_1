#include "fuel-service.h"
#include "event-bus/events.h"
#include "fuel-state.h"

FuelService::FuelService(EventBus& bus, AircraftConfiguration aircraftConfig) : bus(bus) {
    this->Subscribe();
    this->Low_Fuel_Warning_Threshold = aircraftConfig.fuelThresholds.low_fuel_warning_threshold;
}

// Subscriptions to other services
void FuelService::Subscribe() { 
    // Listen for new sensor outputs from the sensors
    bus.subscribe<NewFuelLevelSensorOutput>(
        [this](const NewFuelLevelSensorOutput& event)
        {
            this->CheckFuelLevelChanged(event.Output_Fuel_Level);
            this->CheckFuelConsumptionChanged(event.Output_Fuel_Consumption); 
        }
    );
    bus.subscribe<NewAirSpeedSensorOutput>(
        [this](const NewAirSpeedSensorOutput& event)
        {
            this->CheckAirSpeedChanged(event.Output_Airspeed);
        }
    );
}

// -------------------------------------------------------------------------------------
// Fuel Level Changed

void FuelService::CheckFuelLevelChanged(float New_Fuel_Level) {
    if (this->Fuel_Level != New_Fuel_Level) {
        UpdateFuelLevel(New_Fuel_Level);
        CheckLowFuelWarning();
        CheckLowFuelWarningCleared;
    }
}

void FuelService::UpdateFuelLevel(float New_Fuel_Level) {
    this->Fuel_Level == New_Fuel_Level;
    bus.publish(FuelLevelChanged{New_Fuel_Level}); 
} 

// ----------------------------------------------------------------------------------
// Air speed changed

void FuelService::CheckAirSpeedChanged(float New_Air_Speed) {
    if (this->Air_Speed != New_Air_Speed) {
        UpdateAirSpeed(New_Air_Speed);
    }
}

void FuelService::UpdateAirSpeed(float New_Air_Speed) {
    this->Air_Speed == New_Air_Speed;
    bus.publish(AirSpeedChanged{New_Air_Speed});
}

// -----------------------------------------------------------------------------------
// Fuel consumption

void FuelService::CheckFuelConsumptionChanged(float New_Fuel_Consumption) {
    if (this->Fuel_Consumption != New_Fuel_Consumption) {
        UpdateFuelConsumption(New_Fuel_Consumption);
    }
}

void FuelService::UpdateFuelConsumption(float New_Fuel_Consumption) {
    bus.publish(FuelConsumptionChanged{New_Fuel_Consumption}); 
    this->Fuel_Consumption = New_Fuel_Consumption; 
}

// -----------------------------------------------------------------------------------
// Fuel Range 

void FuelService::UpdateFuelRange(float New_Fuel_Level, float New_Air_Speed) {
    float Endurance = New_Fuel_Level/this->Fuel_Consumption;
    float New_Range = New_Air_Speed*Endurance;
    this->Fuel_Range = New_Range; 
    bus.publish(FuelRangeChanged{New_Range}); 
}

void FuelService::UpdateFuelLevel(float New_Fuel_Level) {
    float Endurance = New_Fuel_Level/this->Fuel_Consumption;
    float New_Range = this->Air_Speed*Endurance;
    this->Fuel_Range = New_Range; 
    bus.publish(FuelRangeChanged{New_Range}); 
}

void FuelService::UpdateFuelLevel(float New_Air_Speed) {
    float Endurance = this->Fuel_Level/this->Fuel_Consumption;
    float New_Range = New_Air_Speed*Endurance;
    this->Fuel_Range = New_Range; 
    bus.publish(FuelRangeChanged{New_Range}); 
}

// -------------------------------------------------------------------------------
// Low fuel warning transitions

// CLEAR

void FuelService::CheckLowFuelWarningCleared() {
    if (this->fuelState == FuelState::WARN) {
        if (this->Fuel_Level > this->Low_Fuel_Warning_Threshold) {
            ClearLowFuelWarning();
        }
    }
}

void FuelService::ClearLowFuelWarning() {
    this->fuelState == FuelState::NORMAL;
    bus.publish(LowFuelWarningCleared{});
}

// RAISE

void FuelService::CheckLowFuelWarning() {
    if (this->fuelState == FuelState::NORMAL) {
        if (this->Fuel_Level < this->Low_Fuel_Warning_Threshold) {
            RaiseLowFuelWarning();
        }
    }
}

void FuelService::RaiseLowFuelWarning() {
    this->fuelState == FuelState::WARN; 
    bus.publish(LowFuelWarningRaised{fuelState}); 
}