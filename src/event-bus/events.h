// Events.hpp
#include "fuel/fuel-state.h"

#pragma once

struct FuelLevelChanged
{
    float New_Fuel_Level;
};

struct FuelConsumptionChanged
{
    float New_Fuel_Consumption;
};

struct RangeChanged
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