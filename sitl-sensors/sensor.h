#ifndef SENSOR_H
#define SENSOR_H

class Sensor {
public:
    ~Sensor();
    virtual float GetData(float minimum, float maximum) = 0; // Pure virtual function, must be implemented by derived classes
    virtual void PrintData() = 0; // Pure virtual function, must be implemented by derived classes
private:
    bool initialized = false;
};

#endif // SENSOR_H