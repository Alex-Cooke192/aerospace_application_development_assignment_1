// Events.hpp
#include "fuel/fuel-state.h"

#pragma once

struct NewFuelLevelSensorOutput
{
    float Output_Fuel_Level;
    float Output_Fuel_Consumption; 
};

struct NewFuelConsumptionSensorOutput
{
    float Output_Fuel_Consumption;
};

struct FuelLevelChanged
{
    float Original_Fuel_Level;
    float New_Fuel_Level;
};

struct FuelConsumptionChanged
{
    float Original_Fuel_Consumption;
    float New_Fuel_Consumption;
};

struct FuelRangeChanged
{
    float Original_Fuel_Range;
    float New_Fuel_Range;
};

struct LowFuelWarningRaised
{
    FuelState fuelState;
    float Fuel_Level; 
};

struct LowFuelWarningCleared
{
    FuelState fuelState; 
    float Fuel_Level; 
};

struct FuelSensorFaultDetected
{
};

struct FuelSensorFaultCleared
{
}; 