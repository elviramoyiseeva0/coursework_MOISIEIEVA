#pragma once
#include "Vehicle.h"

class Truck : public Vehicle
{
private:
    double liftingCapacity;

public:
    Truck(double weight_, double maxSpeed_, double fuelConsumption_, double liftingCapacity_);

    void displayInfo() const override;
    int calculateComfort() const override;
    int getPassengerCapacity() const override;
    double getCargoCapacity() const override;
};

