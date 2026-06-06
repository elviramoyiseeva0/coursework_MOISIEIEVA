#include <iostream>
#include <stdexcept>
#include "TransportSystem.h"
#include "Motorcycle.h"
#include "Car.h"
#include "Truck.h"
#include "Bus.h"

void displayMenu()
{
    std::cout << "\n--- FLEET MENU ---\n";
    std::cout << "1. Add Car\n";
    std::cout << "2. Add Motorcycle\n";
    std::cout << "3. Add Truck\n";
    std::cout << "4. Add Bus\n";
    std::cout << "5. Show all vehicles\n";
    std::cout << "6. Find best vehicle for the trip\n";
    std::cout << "0. Exit\n";
    std::cout << "Your choice: ";
}

int main()
{

    TransportSystem transportSystem;
    int choice = -1;

    while (choice != 0)
    {
        displayMenu();
        std::cin >> choice;

        try
        {
            if (choice == 1)
            {
                double weight, maxSpeed, fuelConsumption, maxBaggage;
                int passengerCount;

                std::cout << "\n--- Enter parameters for Car ---\n";

                std::cout << "Weight (kg): ";
                std::cin >> weight;

                std::cout << "Max Speed (km/h): ";
                std::cin >> maxSpeed;

                std::cout << "Fuel Consumption (L/100km): ";
                std::cin >> fuelConsumption;

                std::cout << "Max Baggage (kg): ";
                std::cin >> maxBaggage;

                std::cout << "Passenger Count: ";
                std::cin >> passengerCount;

                transportSystem.addVehicle(new Car(weight, maxSpeed, fuelConsumption, maxBaggage, SEGMENT_B, SEDAN, passengerCount, ALCANTARA));

                std::cout << "Car added successfully!" << std::endl;
            }
            else if (choice == 2)
            {
                double weight, maxSpeed, fuelConsumption;
                bool isHasASidecar;

                std::cout << "\n--- Enter parameters for Motorcycle ---\n";

                std::cout << "Weight (kg): ";
                std::cin >> weight;

                std::cout << "Max Speed (km/h): ";
                std::cin >> maxSpeed;

                std::cout << "Fuel Consumption (L/100km): ";
                std::cin >> fuelConsumption;

                std::cout << "Has a sidecar? (1 - Yes, 0 - No): ";
                std::cin >> isHasASidecar;

                transportSystem.addVehicle(new Motorcycle(weight, maxSpeed, fuelConsumption, isHasASidecar));

                std::cout << "Motorcycle added successfully!" << std::endl;
            }
            else if (choice == 3)
            {
                double weight, maxSpeed, fuelConsumption, liftingCapacity;

                std::cout << "\n--- Enter parameters for Truck ---\n";

                std::cout << "Weight (kg): ";
                std::cin >> weight;

                std::cout << "Max Speed (km/h): ";
                std::cin >> maxSpeed;

                std::cout << "Fuel Consumption (L/100km): ";
                std::cin >> fuelConsumption;

                std::cout << "Lifting Capacity (kg): ";
                std::cin >> liftingCapacity;

                transportSystem.addVehicle(new Truck(weight, maxSpeed, fuelConsumption, liftingCapacity));

                std::cout << "Truck added successfully!" << std::endl;
            }
            else if (choice == 4)
            {
                double weight, maxSpeed, fuelConsumption, maxBaggagePerPassenger;
                int passengerCount, convenienceOfVisions;
                bool isHasAirConditioning, isHasFoldingSeats;

                std::cout << "\n--- Enter parameters for Bus ---\n";

                std::cout << "Weight (kg): ";
                std::cin >> weight;

                std::cout << "Max Speed (km/h): ";
                std::cin >> maxSpeed;

                std::cout << "Fuel Consumption (L/100km): ";
                std::cin >> fuelConsumption;

                std::cout << "Passenger Count: ";
                std::cin >> passengerCount;

                std::cout << "Max Baggage Per Passenger (kg): ";
                std::cin >> maxBaggagePerPassenger;

                std::cout << "Seat Comfort Level / Convenience (1-10): ";
                std::cin >> convenienceOfVisions;

                std::cout << "Has Air Conditioning? (1 - Yes, 0 - No): ";
                std::cin >> isHasAirConditioning;

                std::cout << "Has Folding Seats? (1 - Yes, 0 - No): ";
                std::cin >> isHasFoldingSeats;

                transportSystem.addVehicle(new Bus(weight, maxSpeed, fuelConsumption, passengerCount, isHasAirConditioning, isHasFoldingSeats, convenienceOfVisions, maxBaggagePerPassenger));

                std::cout << "Bus added successfully!" << std::endl;
            }
            else if (choice == 5)
            {
                transportSystem.displayAllVehicles();
            }
            else if (choice == 6)
            {
                int requiredPassengers;
                double totalCargoWeight;

                std::cout << "\n--- Find The Best Vehicle ---\n";

                std::cout << "How many passengers need to be transported? ";
                std::cin >> requiredPassengers;

                std::cout << "What is the total weight of the cargo (kg)? ";
                std::cin >> totalCargoWeight;

                transportSystem.findBestVehicleForJob(requiredPassengers, totalCargoWeight);
}
        }
        catch (const std::invalid_argument& e)
        {
            std::cout << "\nERROR: " << e.what() << "\nTry again.\n";
        }
    }

    std::cout << "Program finished." << std::endl;
    return 0;
}