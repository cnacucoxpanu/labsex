#include "Train.h"
#include <iostream>

Train::Train() : PassengerPerevozchik(), wagonCount(0), comfortClass("") {}

Train::Train(const std::string& n, double s, double c, double d, int wagons, const std::string& comfort)
    : PassengerPerevozchik(n, s, c, d), wagonCount(wagons), comfortClass(comfort) {}

void Train::setWagonCount(int count) {
    wagonCount = count;
}

int Train::getWagonCount() const {
    return wagonCount;
}

void Train::setComfortClass(const std::string& comfort) {
    comfortClass = comfort;
}

std::string Train::getComfortClass() const {
    return comfortClass;
}

double Train::calculateCost() const {
    double multiplier = 1.0;
    if (comfortClass == "luxury") multiplier = 1.5;
    else if (comfortClass == "coupe") multiplier = 1.2;
    else if (comfortClass == "platzkart") multiplier = 1.0;
    
    return distance * cost * multiplier;
}

double Train::calculateTime() const {
    double stopTime = (distance / 100) * (5.00 / 60);
    return (distance / speed) + stopTime;
}

bool Train::operator==(const Train& other) const {
    return (PassengerPerevozchik::operator==(other) &&
            wagonCount == other.wagonCount &&
            comfortClass == other.comfortClass);
}

bool Train::operator!=(const Train& other) const {
    return !(*this == other);
}

Train& Train::operator=(const Train& other) {
    if (this != &other) {
        PassengerPerevozchik::operator=(other);
        wagonCount = other.wagonCount;
        comfortClass = other.comfortClass;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Train& train) {
    os << "=== TRAIN ===\n"
       << "Name: " << train.getName() << "\n"
       << "Speed: " << train.getSpeed() << " km/h\n"
       << "Cost per km: " << train.getCost() << " BYN\n"
       << "Distance: " << train.getDistance() << " km\n"
       << "Wagon count: " << train.getWagonCount() << "\n"
       << "Comfort class: " << train.getComfortClass() << "\n"
       << "Total time (with stops): " << train.calculateTime() << " h\n"
       << "Total cost (with class): " << train.calculateCost() << " BYN";
    return os;
}

std::istream& operator>>(std::istream& is, Train& train) {
    std::string name, comfort;
    double speed, cost, distance;
    int wagons;
    
    std::cout << "Enter name: ";
    getline(is, name);
    std::cout << "Enter speed (km/h): ";
    is >> speed;
    std::cout << "Enter cost per km (BYN): ";
    is >> cost;
    std::cout << "Enter distance (km): ";
    is >> distance;
    std::cout << "Enter wagon count: ";
    is >> wagons;
    is.ignore();
    std::cout << "Enter comfort class (luxury/coupe/platzkart): ";
    getline(is, comfort);
    
    train.setName(name);
    train.setSpeed(speed);
    train.setCost(cost);
    train.setDistance(distance);
    train.setWagonCount(wagons);
    train.setComfortClass(comfort);
    
    return is;
}