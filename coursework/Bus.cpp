#include "Bus.h"
#include <iostream>
#include <stdexcept>
Bus::Bus(double weight_, double maxSpeed_, double fuelConsumption_, int passengerCount_, bool isHasAirConditioning_, bool isHasFoldingSeats_, int convenienceOfVisions_, double maxBaggagePerPassenger_)
    : Vehicle(weight_, maxSpeed_, fuelConsumption_) {
    if (passengerCount_ <= 0 || convenienceOfVisions_ < 1 || convenienceOfVisions_ > 10 || maxBaggagePerPassenger_ < 0)
    {
        throw std::invalid_argument("ERROR! Incorrect data for bus. Try again.");
    }
    passengerCount = passengerCount_;
    isHasAirConditioning = isHasAirConditioning_;
    isHasFoldingSeats = isHasFoldingSeats_;
    convenienceOfVisions = convenienceOfVisions_;
    maxBaggagePerPassenger = maxBaggagePerPassenger_;
}

void Bus::displayInfo() const
{
    std::cout << "[Bus] Number of passangers: " << passengerCount << ", Air conditioning: " << (isHasAirConditioning ? "Yes" : "No") << "\n";
}

int Bus::calculateComfort() const
{
    int comfort = convenienceOfVisions;
    if (isHasAirConditioning)
    {
        comfort += 2;
    }
    if (isHasFoldingSeats)
    {
        comfort += 2;
    }
    return comfort;
}

int Bus::getPassengerCapacity() const { return passengerCount; }
double Bus::getCargoCapacity() const { return passengerCount * maxBaggagePerPassenger; }