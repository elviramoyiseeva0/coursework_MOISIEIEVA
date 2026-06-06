#pragma once
#include "Vehicle.h"

class Bus : public Vehicle
{
private:
    int passengerCount;
    bool isHasAirConditioning;
    bool isHasFoldingSeats;
    int convenienceOfVisions;
    double maxBaggagePerPassenger;

public:
    Bus(double weight_, double maxSpeed_, double fuelConsumption_, int passengerCount_, bool isHasAirConditioning_, bool isHasFoldingSeats_, int convenienceOfVisions_, double maxBaggagePerPassenger_);

    void displayInfo() const override;
    int calculateComfort() const override;
    int getPassengerCapacity() const override;
    double getCargoCapacity() const override;
};