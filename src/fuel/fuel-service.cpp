


void FuelService::UpdateFuelLevel(float New_Fuel_Level) {
    if (this->Fuel_Level != New_Fuel_Level) {
        bus.publish(FuelLevelChanged{New_Fuel_Level}); 
        this->Previous_Fuel_Level = New_Fuel_Level; 
    }
} 

void FuelService::UpdateFuelConsumption() {
    if (this->Fuel_Consumption != New_Fuel_Consumption) {
        bus.publish(FuelConsumptionChanged{New_Fuel_Consumption}); 
        this->Fuel_Consumption = New_Fuel_Consumption; 
    }
}

void EventDetector::UpdateRange() {
    if (this->Fuel_level != New_Fuel_Level) {
        
    }
}

void EventDetector::ClearLowFuelWarning() {
    if (this->Fuel_State == WARN) {
        if (this->Fuel_Level > this->Low_Fuel_Warning_Threshold) {
            bus.publish(LowFuelWarningCleared{})
        }
    }
}

void EventDetector::RaiseLowFuelWarning() {
    if (this->Fuel_State == NORMAL) {
        if (this->Fuel_Level < this->Low_Fuel_Warning_Threshold) {
        bus.publish(LowFuelWarningRaised{}); 
        }
    }
}