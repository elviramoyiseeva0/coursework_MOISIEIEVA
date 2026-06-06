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
    std::cout << "[Truck] Lifting capacity: " << liftingCapacity << " kg\n";
}

int Truck::calculateComfort() const
{
    return 0;
}

int Truck::getPassengerCapacity() const { return 0; }
double Truck::getCargoCapacity() const { return liftingCapacity; }