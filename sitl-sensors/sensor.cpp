class Sensor {
public:
    Sensor();
    virtual float GetData() = 0; // Pure virtual function, must be implemented by derived classes
    virtual void PrintData() = 0; // Pure virtual function, must be implemented by derived classes
private:
    bool initialized = false;
};

