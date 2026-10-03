#include "event-bus/event-bus.h"
#include "fuel-state.h"

class FuelService {
public:
    FuelService(EventBus& bus) : bus(bus) {};
    void Subscribe(); 
    
    void UpdateFuelLevel(float New_Fuel_Level);
    void UpdateFuelConsumption(float New_Fuel_Consumption);
    void RaiseLowFuelWarning();
    void ClearLowFuelWarning();
    void UpdateRange(float New_Fuel_Level);
private:
    EventBus& bus;
    float Low_Fuel_Warning_Threshold = 20.0; 

    float Fuel_Level = 0.0;
    float Fuel_Consumption = 0.0;
    FuelState fuelState = FuelState::NORMAL; 
};
