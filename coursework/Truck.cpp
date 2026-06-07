#include "Truck.h"
#include <iostream>
#include <stdexcept>

Truck::Truck(double weight_, double maxSpeed_, double fuelConsumption_, double liftingCapacity_)
    : Vehicle(weight_, maxSpeed_, fuelConsumption_)
{
    if (liftingCapacity_ <= 0) {
        throw std::invalid_argument("ERROR! Lifting capacity must be more than 0.");
    }
    liftingCapacity = liftingCapacity_;
}

void Truck::displayInfo() const
{
    std::cout << "[Truck]   Weight: " << getWeight() << " kg\n";
    std::cout << "       Max Speed: " << getMaxSpeed() << " km/h\n";
    std::cout << "Fuel Consumption: " << getFuelConsumption() << " L/100km\n";
    std::cout << "Lifting capacity: " << liftingCapacity << " kg" << std::endl;
}

int Truck::calculateComfort() const
{
    return 0;
}

int Truck::getPassengerCapacity() const { return 0; }
double Truck::getCargoCapacity() const { return liftingCapacity; }