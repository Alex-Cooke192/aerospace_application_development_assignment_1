class SensorHealthService {
public:
    SensorHealthService(EventBus& bus) : bus(bus) {}
    void RaiseSensorFaultWarning();
    void ClearSensorFaultWarning();
private:
    EventBus& bus;
};
