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

        if (std::cin.fail())
        {
            std::cin.clear(); 
            std::cin.ignore(10000, '\n');
            std::cout << "\nERROR: Invalid input! Please enter a number.\n";
            continue;
        }
        if (choice < 0 || choice > 6)
        {
            std::cout << "\nERROR: Invalid menu choice! Please enter a number from 0 to 6.\n";
            continue;
        }

        try
        {
            if (choice == 1)
            {
                double weight, maxSpeed, fuelConsumption, maxBaggage;
                int passengerCount, segment, body, upholstery;

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

                std::cout << "Car Segment (0-A, 1-B, 2-C, 3-D, 4-E, 5-F, 6-J, 7-S, 8-M): ";
                std::cin >> segment;

                std::cout << "Body Type (0-Sedan, 1-Wagon, 2-Cabriolet): ";
                std::cin >> body;

                std::cout << "Seat Upholstery (0-Cloth, 1-Suede, 2-Vinyl, 3-Alcantara, 4-Eco_Leather, 5-Genuine_Leather): ";
                std::cin >> upholstery;

                if (segment < 0 || segment > 8 || body < 0 || body > 2 || upholstery < 0 || upholstery > 5)
                {
                    throw std::invalid_argument("Invalid choice for segment, body, or upholstery! Please enter correct numbers.");
                }

                transportSystem.addVehicle(new Car(weight, maxSpeed, fuelConsumption, maxBaggage, static_cast<CarSegment>(segment), static_cast<BodyType>(body), passengerCount, static_cast<SeatUpholsteryType>(upholstery)));

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