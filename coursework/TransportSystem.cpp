#include "TransportSystem.h"
#include <iostream>

TransportSystem::TransportSystem()
{
    maxCapacity = 5;
    currentCount = 0;
    vehicles = new Vehicle * [maxCapacity];
}

TransportSystem::~TransportSystem()
{
    for (int i = 0; i < currentCount; ++i)
    {
        delete vehicles[i];
    }
    delete[] vehicles;
}

void TransportSystem::resizeArray()
{
    maxCapacity *= 2;
    Vehicle** newVehicles = new Vehicle * [maxCapacity];
    for (int i = 0; i < currentCount; ++i)
    {
        newVehicles[i] = vehicles[i];
    }
    delete[] vehicles;
    vehicles = newVehicles;
}

void TransportSystem::addVehicle(Vehicle* vehicle)
{
    if (currentCount == maxCapacity)
    {
        resizeArray();
    }
    vehicles[currentCount] = vehicle;
    currentCount++;
}

void TransportSystem::displayAllVehicles() const
{
    if (currentCount == 0)
    {
        std::cout << "The vehicle fleet is empty.\n";
        return;
    }
    for (int i = 0; i < currentCount; ++i)
    {
        std::cout << i + 1 << ". ";
        vehicles[i]->displayInfo();
        std::cout << "   Comfort Level: " << vehicles[i]->calculateComfort() << "\n";
    }
}

void TransportSystem::findBestVehicleForJob(int requiredPassengers, double totalCargoWeight) const
{
    int theBestVehicle = -1;
    int maxComfortLevel = -1;

    for (int i = 0; i < currentCount; ++i)
    {
        if (vehicles[i]->getPassengerCapacity() >= requiredPassengers &&
            vehicles[i]->getCargoCapacity() >= totalCargoWeight)
        {

            int currentComfort = vehicles[i]->calculateComfort();
            if (currentComfort > maxComfortLevel)
            {
                maxComfortLevel = currentComfort;
                theBestVehicle = i;
            }
        }
    }

    if (theBestVehicle != -1)
    {
        std::cout << "\nBest vehicle is: \n";
        vehicles[theBestVehicle]->displayInfo();
    }
    else
    {
        std::cout << "\nUnfortunately, no suitable vehicle was found for these requirements.\n";
    }
}