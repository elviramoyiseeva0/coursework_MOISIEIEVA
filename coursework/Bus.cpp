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
    std::cout << "[Bus]               Weight: " << getWeight() << " kg\n";
    std::cout << "                 Max Speed: " << getMaxSpeed() << " km/h\n";
    std::cout << "          Fuel Consumption: " << getFuelConsumption() << " L/100km\n";
    std::cout << "                Passengers: " << passengerCount << "\n";
    std::cout << "          Air Conditioning: " << (isHasAirConditioning ? "Yes" : "No") << "\n";
    std::cout << "             Folding Seats: " << (isHasFoldingSeats ? "Yes" : "No") << "\n";
    std::cout << "              Base Comfort: " << convenienceOfVisions << "/10\n";
    std::cout << " Max Baggage Per Passenger: " << maxBaggagePerPassenger << " kg" << std::endl;
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