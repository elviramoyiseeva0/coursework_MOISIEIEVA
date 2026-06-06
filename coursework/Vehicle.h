#pragma once
#include <string>

class Vehicle
{
private:
    double weight;           
    double maxSpeed;         
    double fuelConsumption;  

public:
    Vehicle(double weight_, double maxSpeed_, double fuelConsumption_);
    virtual ~Vehicle(); 

    double getWeight() const;
    double getMaxSpeed() const;
    double getFuelConsumption() const;

    virtual void displayInfo() const = 0;
    virtual int calculateComfort() const = 0;

    virtual int getPassengerCapacity() const = 0;
    virtual double getCargoCapacity() const = 0;
};

