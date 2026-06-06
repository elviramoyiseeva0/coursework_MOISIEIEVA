#pragma once
#include "Vehicle.h"

class Motorcycle : public Vehicle
{
private:
    bool isHasASidecar;

public:
    Motorcycle(double weight_, double maxSpeed_, double fuelConsumption_, bool isHasASidecar_);

    void displayInfo() const override;
    int calculateComfort() const override;
    int getPassengerCapacity() const override;
    double getCargoCapacity() const override;
};

