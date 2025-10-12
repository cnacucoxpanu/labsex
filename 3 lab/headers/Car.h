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

    double calculateCost() const override;
    double calculateTime() const override;

    // Операторы сравнения
    bool operator==(const Car& other) const;
    bool operator!=(const Car& other) const;
    
    // Оператор присваивания
    Car& operator=(const Car& other);
};

#endif