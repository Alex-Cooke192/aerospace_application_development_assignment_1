#pragma once

class Sensor {
public:
    virtual ~Sensor() = default;
    virtual float GetData(float minimum, float maximum) = 0; // Pure virtual function, must be implemented by derived classes
    virtual void PrintData() = 0; // Pure virtual function, must be implemented by derived classes
private:
    bool initialized = false;
};

