
// Aircraft configuration

struct FuelMetrics {
    float fuel_capacity = 250.0f; 
    float fuel_consumption_minimum = 0.01f;
    float fuel_consumption_maximum = 0.05f;
    float fuel_efficiency = 3.0f; // Fuel efficiency simplified to 3 rather than being range dependent, in km/kg
};

struct Airspeeds {
    float minimum_airspeed = 50.0f; // kmph
    float maximum_airspeed = 400.0f; // kmph
};

struct SensorMetrics{
    float fuel_sensor_variability = 0.03;
    float air_speed_sensor_variability = 0.01;
};

struct FuelThresholds {
    float low_fuel_warning_threshold;
    float critical_fuel_warning_threshold;

    FuelThresholds(float fuelCapacity)
        : low_fuel_warning_threshold(fuelCapacity * 0.15f), // 15% of total capacity
          critical_fuel_warning_threshold(fuelCapacity * 0.05f) // 5% of total capacity
    {
    }
};

struct AircraftConfiguration {
    FuelMetrics fuelMetrics;
    FuelThresholds fuelThresholds;
    Airspeeds airspeeds;
    SensorMetrics SensorMetrics;

    AircraftConfiguration()
        : fuelMetrics(),
          fuelThresholds(fuelMetrics.fuel_capacity)
    {
    }
};