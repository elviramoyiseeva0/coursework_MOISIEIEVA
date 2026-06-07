#include "Motorcycle.h"
#include <iostream>

Motorcycle::Motorcycle(double weight_, double maxSpeed_, double fuelConsumption_, bool isHasASidecar_)
    : Vehicle(weight_, maxSpeed_, fuelConsumption_), isHasASidecar(isHasASidecar_)
{}

void Motorcycle::displayInfo() const
{
    std::cout << "[Motorcycle] Weight: " << getWeight() << " kg\n";
    std::cout << "          Max Speed: " << getMaxSpeed() << " km/h\n";
    std::cout << "   Fuel Consumption: " << getFuelConsumption() << " L/100km\n";
    std::cout << "            Sidecar: " << (isHasASidecar ? "Yes" : "No") << std::endl;
}

int Motorcycle::calculateComfort() const
{
    if (isHasASidecar)
    {
        return 4;
    }
    return 2;
}

int Motorcycle::getPassengerCapacity() const
{
    if (isHasASidecar)
    {
        return 2;
    }
    return 1;
}

double Motorcycle::getCargoCapacity() const
{
    return 0;
}