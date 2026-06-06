#include "Car.h"
#include <iostream>
#include <stdexcept>

Car::Car(double weight_, double maxSpeed_, double fuelConsumption_, double maxBaggage_, CarSegment carSegment_, BodyType bodyType_, int passengerCount_, SeatUpholsteryType seatUpholsteryType_)
    : Vehicle(weight_, maxSpeed_, fuelConsumption_)
{
    if (maxBaggage_ <= 0 || passengerCount_ <= 0)
    {
        throw std::invalid_argument("ERROR! Max baggage and number of passengers must be more than 0. Try again.");
    }
    maxBaggage = maxBaggage_;
    carSegment = carSegment_;
    bodyType = bodyType_;
    passengerCount = passengerCount_;
    seatUpholsteryType = seatUpholsteryType_;
}

void Car::displayInfo() const
{
    std::cout << "[Car] Number of passengers: " << passengerCount << ", Max baggage: " << maxBaggage << " kg\n";
}
int Car::calculateComfort() const
{
    int comfort = 5;
    if (seatUpholsteryType == ALCANTARA || seatUpholsteryType == GENUINE_LEATHER)
    {
        comfort += 2;
    }
    if (bodyType == CABRIOLET)
    {
        comfort += 1;
    }
    return comfort;
}

int Car::getPassengerCapacity() const { return passengerCount; }
double Car::getCargoCapacity() const { return maxBaggage; }