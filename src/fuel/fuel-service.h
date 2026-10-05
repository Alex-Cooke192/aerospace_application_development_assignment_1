#include "event-bus/event-bus.h"
#include "fuel-state.h"
#include "aircraft-configuration.h"

class FuelService {
public:
    FuelService(EventBus& bus, struct AircraftConfiguration);
    void Subscribe(); 
    
    void UpdateFuelLevel(float New_Fuel_Level);
    void UpdateFuelConsumption(float New_Fuel_Consumption);
    void RaiseLowFuelWarning();
    void ClearLowFuelWarning();
    void UpdateFuelRange(float New_Fuel_Level);

private:
    EventBus& bus;
    // Preset values
    float Low_Fuel_Warning_Threshold = 20.0; // Standard default for low fuel in case not given
    float Fuel_Efficiency = 8.0; // This is the Km travelled per kg of fuel
    
    // This value is read only, ued to calculate range etc. 
    //Fuel service should never modify this value
    float FUEL_CAPACITY = 100.0;

    // Measured values
    float Fuel_Level = 0.0;
    float Fuel_Consumption = 0.0;
    float Fuel_Range = 0.0;
    FuelState fuelState = FuelState::NORMAL; 
};
