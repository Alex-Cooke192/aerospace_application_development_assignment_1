#include "event-bus/event-bus.h"
#include "fuel-state.h"

class FuelService {
public:
    FuelService(EventBus& bus);
    void Subscribe(); 

    // Checker functions
    void CheckLowFuelWarning();
    void CheckLowFuelClear();
    void CheckFuelConsumptionChanged(float New_Fuel_Consumption);
    void CheckFuelLevelChanged(float New_Fuel_Level);
    
    void UpdateFuelLevel(float New_Fuel_Level);
    void UpdateFuelConsumption(float New_Fuel_Consumption);
    void RaiseLowFuelWarning();
    void RaiseLowFuelWarningCleared();
    void UpdateFuelRange(float New_Fuel_Level);
private:
    EventBus& bus;
    float Low_Fuel_Warning_Threshold = 20.0; 
    float Fuel_Efficiency = 8.0; // This is the Km travelled per kg of fuel

    float Fuel_Level = 0.0;
    float Fuel_Consumption = 0.0;
    float Fuel_Range = 0.0;
    FuelState _Fuel_State = FuelState::NORMAL; 
};
