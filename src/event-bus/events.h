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
    float New_Fuel_Level;
};

struct FuelConsumptionChanged
{
    float New_Fuel_Consumption;
};

struct FuelRangeChanged
{
    double New_Range;
};

struct LowFuelWarningRaised
{
    FuelState fuelState;
};

struct LowFuelWarningCleared
{
    FuelState fuelState; 
};

struct FuelSensorFaultDetected
{
};

struct FuelSensorFaultCleared
{
}; 