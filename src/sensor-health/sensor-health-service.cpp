

void SensorHealthService::RaiseSensorFaultWarning() {
    bus.publish(SensorFaultWarningRaised{});
}

void SensorHealthService::ClearSensorFaultWarning() {
    bus.publish(SensorFaultWarningCleared{});  
}