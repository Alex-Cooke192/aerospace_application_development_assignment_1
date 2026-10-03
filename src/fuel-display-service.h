#include "event-bus/event-bus.h"

class FuelDisplayService {
    public:
    FuelDisplayService(EventBus& EventBus);
    void Subscribe(); 

    void PrintFuelLevelChanged(float New_Fuel_Level);
    void PrintLowFuelWarning(enum FuelState); 
    void PrintLowFuelClear(enum FuelState); 
    void PrintFuelConsumptionChanged(float New_Fuel_Consumption); 
    void PrintRangeChanged(float New_Range); 

    private:
    EventBus& eventBus; 
}; 