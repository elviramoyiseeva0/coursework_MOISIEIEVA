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
    std::string carSegments[] = { "A", "B", "C", "D", "E", "F", "J", "S", "M" };
    std::string bodyTypes[] = { "Sedan", "Wagon", "Cabriolet" };
    std::string seatUpholsteryTypes[] = { "Cloth", "Suede", "Vinyl", "Alcantara", "Eco-leather", "Genuine leather" };

    std::cout << "[Car]         Weight: " << getWeight() << " kg\n";
    std::cout << "           Max Speed: " << getMaxSpeed() << " km/h\n";
    std::cout << "    Fuel Consumption: " << getFuelConsumption() << " L/100km\n";
    std::cout << "         Max Baggage: " << maxBaggage << " kg\n";
    std::cout << "         Car Segment: " << carSegments[carSegment] << "\n";
    std::cout << "           Body Type: " << bodyTypes[bodyType] << "\n";
    std::cout << "     Passenger Count: " << passengerCount << "\n";
    std::cout << "Seat Upholstery Type: " << seatUpholsteryTypes[seatUpholsteryType] << std::endl;
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