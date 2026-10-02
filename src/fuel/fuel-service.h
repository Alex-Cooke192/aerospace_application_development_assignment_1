

class FuelService {
public:
    FuelService(EventBus& bus) : bus(bus) {}
    void UpdateFuelLevel(float New_Fuel_Level);
    void UpdateFuelConsumption();
    void RaiseLowFuelWarning();
    void ClearLowFuelWarning();
private:
    EventBus& bus;

    float Fuel_Level = 0.0;
    float Fuel_Consumption = 0.0;
    enum FuelState {NORMAL, WARN, REFUEL} Fuel_State = NORMAL;
};
