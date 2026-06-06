#include "Vehicle.h"
#include <stdexcept>

Vehicle::Vehicle(double weight_, double maxSpeed_, double fuelConsumption_)
{
    if (weight_ <= 0 || maxSpeed_ <= 0 || fuelConsumption_ <= 0)
    {
        throw std::invalid_argument("ERROR! Weight, max speed and fuel consumption must be more than 0.");
    }
    weight = weight_;
    maxSpeed = maxSpeed_;
    fuelConsumption = fuelConsumption_;
}

Vehicle::~Vehicle() {}

double Vehicle::getWeight() const { return weight; }
double Vehicle::getMaxSpeed() const { return maxSpeed; }
double Vehicle::getFuelConsumption() const { return fuelConsumption; }