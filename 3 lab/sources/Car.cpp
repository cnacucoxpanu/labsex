#include "Car.h"
#include <iostream>


Car::Car() : PassengerCarrier(), passengerCapacity(0), fuelConsumption(0) {}

Car::Car(const std::string& n, double s, double c, double d, int capacity, double consumption) : 
PassengerCarrier(n,s,c,d), passengerCapacity(capacity), fuelConsumption(consumption) {}

void Car::setPassengerCapacity(int capacity) {
    passengerCapacity = capacity;
}

int Car::getPassengerCapacity() const {
    return passengerCapacity;
}

void Car::setFuelConsumption(double consumption) {
    fuelConsumption = consumption;
}

double Car::getFuelConsumption() const {
    return fuelConsumption;
}

double Car::calculateCost() const {
    // Стоимость топлива в BYN (примерно 2 BYN за литр)
    double fuelCost = (distance / 100) * fuelConsumption * 2.0;
    return distance * cost + fuelCost;
}

double Car::calculateTime() const {
    return (distance / speed);
}

std::ostream& Car::output(std::ostream& os) const {
    os << "=== CAR ===\n";
    PassengerCarrier::output(os);
    os << "\nPassenger capacity: " << passengerCapacity << "\n"
       << "Fuel consumption: " << fuelConsumption << " l/100 km\n"
       << "Total time: " << calculateTime() << " h\n"
       << "Total cost (with fuel): " << calculateCost() << " BYN";
    return os;
}

std::istream& Car::input(std::istream& is) {
    PassengerCarrier::input(is);
    std::cout << "Enter passenger capacity: ";
    is >> passengerCapacity;
    std::cout << "Enter fuel consumption (l/100 km): ";
    is >> fuelConsumption;
    is.ignore();
    return is;
}

Car& Car::operator=(const Car& other) {
    if (this != &other) {
        PassengerCarrier::operator=(other);
        passengerCapacity = other.passengerCapacity;
        fuelConsumption = other.fuelConsumption;
    }
    return *this;
}