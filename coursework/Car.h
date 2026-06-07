#pragma once
#include "Vehicle.h"

enum CarSegment { SEGMENT_A, SEGMENT_B, SEGMENT_C, SEGMENT_D, SEGMENT_E, SEGMENT_F, SEGMENT_J, SEGMENT_S, SEGMENT_M };
enum BodyType { SEDAN, WAGON, CABRIOLET };
enum SeatUpholsteryType { CLOTH, SUEDE, VINYL, ALCANTARA, ECO_LEATHER, GENUINE_LEATHER };

class Car : public Vehicle
{
private:
    double maxBaggage;
    CarSegment carSegment;
    BodyType bodyType;
    int passengerCount;
    SeatUpholsteryType seatUpholsteryType;

public:
    Car(double weight_, double maxSpeed_, double fuelConsumption_, double maxBaggage_, CarSegment carSegment_, BodyType bodyType_, int passengerCount_, SeatUpholsteryType seatUpholsteryType_);

    void displayInfo() const override; 
    int calculateComfort() const override;
    int getPassengerCapacity() const override;
    double getCargoCapacity() const override;
};
