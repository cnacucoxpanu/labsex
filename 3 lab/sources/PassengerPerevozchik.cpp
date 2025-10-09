#include "PassengerCarrier.h"

PassengerCarrier::PassengerCarrier() : name(""), speed(0), cost(0), distance(0) {}

PassengerCarrier::PassengerCarrier(const std::string& n, double s, double c, double d) 
: name(n), speed(s), cost(c), distance(d) {}

void PassengerCarrier::setName(const std::string& newName) {
    name = newName;
}

std::string PassengerCarrier::getName() const {
    return name;
}

void PassengerCarrier::setSpeed(double newSpeed) {
    speed = newSpeed;
}

double PassengerCarrier::getSpeed() const {
    return speed;
}

void PassengerCarrier::setCost(double newCost) {
    cost = newCost;
}

double PassengerCarrier::getCost() const {
    return cost;
}

void PassengerCarrier::setDistance(double newDistance) {
    distance = newDistance;
}

double PassengerCarrier::getDistance() const {
    return distance;
}

double PassengerCarrier::calculateTime() const {
    return distance / speed;
}

double PassengerCarrier::calculateCost() const {
    return distance * cost;
}


std::ostream& PassengerCarrier::output(std::ostream& os) const {
    os << "Name: " << name << "\n"
       << "Speed: " << speed << " km/h\n"
       << "Cost per km: " << cost << " BYN\n"
       << "Distance: " << distance << " km\n"
       << "Travel time: " << calculateTime() << " h\n"
       << "Trip cost: " << calculateCost() << " BYN";
    return os;
}

std::istream& PassengerCarrier::input(std::istream& is) {
    std::cout << "Enter name: ";
    getline(is, name);
    std::cout << "Enter speed (km/h): ";
    is >> speed;
    std::cout << "Enter cost per km (BYN): ";
    is >> cost;
    std::cout << "Enter distance (km): ";
    is >> distance;
    is.ignore(); // очистка буфера
    return is;
}

PassengerCarrier& PassengerCarrier::operator=(const PassengerCarrier& other) {
    if(this != &other) {
        name = other.name;
        speed = other.speed;
        cost = other.cost;
        distance = other.distance;
    }
    return *this;
}

PassengerCarrier::~PassengerCarrier() {}

std::ostream& operator<<(std::ostream& os, const PassengerCarrier& carrier) {
    return carrier.output(os);
}

std::istream& operator>>(std::istream& is, PassengerCarrier& carrier) {
    return carrier.input(is);
}