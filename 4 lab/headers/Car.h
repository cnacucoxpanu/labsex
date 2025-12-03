#ifndef CAR_H
#define CAR_H

#include "PassengerPerevozchik.h"

class Car : public PassengerPerevozchik {
private:
    int passengerCapacity;
    double fuelConsumption;

public:
    Car();
    Car(const std::string& n, double s, double c, double d, int capacity, double consumption);

    void setPassengerCapacity(int capacity);
    int getPassengerCapacity() const;
    void setFuelConsumption(double consumption);
    double getFuelConsumption() const;
    void setMenu() override;
    double calculateCost() const override;
    double calculateTime() const override;
    void shapka() const override;
    void print() const override;
    
    friend std::ostream& operator<<(std::ostream& os, const Car& obj) {
        os << obj.getName();
        return os;
    }
};

std::istream& operator>>(std::istream& is, Car& car);

#endif