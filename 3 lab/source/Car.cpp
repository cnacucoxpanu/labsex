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
    double fuelCost = (distance / 100) * fuelConsumption * 40.0;
    return distance * cost + fuelCost;
}

double Car::calculateTime() const {
    return (distance / speed);
}

std::ostream& Car::output(std::ostream& os) const {
    os << "=== АВТОМОБИЛЬ ===\n";
    PassengerCarrier::output(os);
    os << "\nВместимость пассажиров: " << passengerCapacity << "\n"
       << "Расход топлива: " << fuelConsumption << " л/100 км\n"
       << "Общее время (с учетом пробок): " << calculateTime() << " ч\n"
       << "Общая стоимость (с учетом топлива): " << calculateCost() << " руб.";
    return os;
}

std::istream& Car::input(std::istream& is) {
    PassengerCarrier::input(is);
    std::cout << "Введите вместимость пассажиров: ";
    is >> passengerCapacity;
    std::cout << "Введите расход топлива (л/100 км): ";
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
