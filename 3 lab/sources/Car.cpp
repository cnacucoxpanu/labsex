#include "Car.h"
#include <iostream>

Car::Car() : PassengerPerevozchik(), passengerCapacity(0), fuelConsumption(0) {}

Car::Car(const std::string& n, double s, double c, double d, int capacity, double consumption) : 
PassengerPerevozchik(n,s,c,d), passengerCapacity(capacity), fuelConsumption(consumption) {}

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
    double fuelCost = (distance / 100) * fuelConsumption * 2.0;
    return distance * cost + fuelCost;
}

double Car::calculateTime() const {
    return (distance / speed);
}

bool Car::operator==(const Car& other) const {
    return (PassengerPerevozchik::operator==(other) &&
            passengerCapacity == other.passengerCapacity &&
            fuelConsumption == other.fuelConsumption);
}

bool Car::operator!=(const Car& other) const {
    return !(*this == other);
}

Car& Car::operator=(const Car& other) {
    if (this != &other) {
        PassengerPerevozchik::operator=(other);
        passengerCapacity = other.passengerCapacity;
        fuelConsumption = other.fuelConsumption;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Car& car) {
    os << "=== CAR ===\n"
       << "Name: " << car.getName() << "\n"
       << "Speed: " << car.getSpeed() << " km/h\n"
       << "Cost per km: " << car.getCost() << " BYN\n"
       << "Distance: " << car.getDistance() << " km\n"
       << "Passenger capacity: " << car.getPassengerCapacity() << "\n"
       << "Fuel consumption: " << car.getFuelConsumption() << " l/100 km\n"
       << "Total time: " << car.calculateTime() << " h\n"
       << "Total cost (with fuel): " << car.calculateCost() << " BYN";
    return os;
}

std::istream& operator>>(std::istream& is, Car& car) {
    std::string name;
    double speed, cost, distance, consumption;
    int capacity;
    
    std::cout << "Enter name: ";
    getline(is, name);
    std::cout << "Enter speed (km/h): ";
    is >> speed;
    std::cout << "Enter cost per km (BYN): ";
    is >> cost;
    std::cout << "Enter distance (km): ";
    is >> distance;
    std::cout << "Enter passenger capacity: ";
    is >> capacity;
    std::cout << "Enter fuel consumption (l/100 km): ";
    is >> consumption;
    is.ignore();
    
    car.setName(name);
    car.setSpeed(speed);
    car.setCost(cost);
    car.setDistance(distance);
    car.setPassengerCapacity(capacity);
    car.setFuelConsumption(consumption);
    
    return is;
}