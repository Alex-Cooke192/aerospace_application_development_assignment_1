// Events.hpp

#pragma once

struct FuelLevelChanged
{
    double litres;
};

struct FuelConsumptionChanged
{
    double litresPer100Km;
};

struct RangeChanged
{
    double rangeKm;
};

struct LowFuelWarningRaised
{
};

struct LowFuelWarningCleared
{
};

struct FuelSensorFaultDetected
{
};

struct FuelSensorFaultCleared
{
}; 