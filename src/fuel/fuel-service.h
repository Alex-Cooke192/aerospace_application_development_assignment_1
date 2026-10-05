#include "event-bus/event-bus.h"
#include "fuel-state.h"

class FuelService {
public:
    FuelService(EventBus& bus, struct AircraftConfiguration);
    void Subscribe(); 

    // Checks
    void CheckFuelLevelChanged(float New_Fuel_Level);
    void CheckFuelConsumptionChanged(float New_Fuel_Consumption);
    void CheckAirSpeedChanged(float New_Air_Speed);
    void CheckLowFuelWarning();
    void CheckLowFuelWarningCleared();
    
    // Transitions/updates
    void UpdateFuelLevel(float New_Fuel_Level);
    void UpdateFuelConsumption(float New_Fuel_Consumption);
    void UpdateAirSpeed(float New_Air_Speed);
    void RaiseLowFuelWarning();
    void ClearLowFuelWarning();

    // Overloading...
    void UpdateFuelRange(float New_Fuel_Level, float New_Air_Speed);
    void UpdateFuelRange(float New_Fuel_Level); 
    void UpdateFuelRange(float New_Air_Speed);

private:
    EventBus& bus;
    // Preset values
    float Low_Fuel_Warning_Threshold = 20.0; // Standard default for low fuel in case not given
    
    // This value is read only, ued to calculate range etc. 
    //Fuel service should never modify this value
    float FUEL_CAPACITY = 100.0;

    // Measured values
    float Air_Speed = 0.0;
    float Fuel_Level = 0.0;
    float Fuel_Consumption = 0.0; // Fuel consumed per second
    float Fuel_Range = 0.0;
    FuelState fuelState = FuelState::NORMAL; 
};
