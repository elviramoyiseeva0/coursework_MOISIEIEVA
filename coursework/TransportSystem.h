#pragma once
#include "Vehicle.h"

class TransportSystem
{
private:
    Vehicle** vehicles;
    int currentCount;
    int maxCapacity;

    void resizeArray();

public:
    TransportSystem();
    ~TransportSystem();

    void addVehicle(Vehicle* vehicle);
    void displayAllVehicles() const;

    void findBestVehicleForJob(int requiredPassengers, double totalCargoWeight) const;
};