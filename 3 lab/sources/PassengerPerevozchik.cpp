#include "PassengerPerevozchik.h"

PassengerPerevozchik::PassengerPerevozchik() : name(""), speed(0), cost(0), distance(0) {}

PassengerPerevozchik::PassengerPerevozchik(const std::string& n, double s, double c, double d) 
: name(n), speed(s), cost(c), distance(d) {}

void PassengerPerevozchik::setName(const std::string& newName) {
    name = newName;
}

std::string PassengerPerevozchik::getName() const {
    return name;
}

void PassengerPerevozchik::setSpeed(double newSpeed) {
    speed = newSpeed;
}

double PassengerPerevozchik::getSpeed() const {
    return speed;
}

void PassengerPerevozchik::setCost(double newCost) {
    cost = newCost;
}

double PassengerPerevozchik::getCost() const {
    return cost;
}

void PassengerPerevozchik::setDistance(double newDistance) {
    distance = newDistance;
}

double PassengerPerevozchik::getDistance() const {
    return distance;
}

double PassengerPerevozchik::calculateTime() const {
    return distance / speed;
}

double PassengerPerevozchik::calculateCost() const {
    return distance * cost;
}

bool PassengerPerevozchik::operator==(const PassengerPerevozchik& other) const {
    return (name == other.name && speed == other.speed && 
            cost == other.cost && distance == other.distance);
}

bool PassengerPerevozchik::operator!=(const PassengerPerevozchik& other) const {
    return !(*this == other);
}

PassengerPerevozchik& PassengerPerevozchik::operator=(const PassengerPerevozchik& other) {
    if(this != &other) {
        name = other.name;
        speed = other.speed;
        cost = other.cost;
        distance = other.distance;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const PassengerPerevozchik& carrier) {
    os << "Name: " << carrier.getName() << "\n"
       << "Speed: " << carrier.getSpeed() << " km/h\n"
       << "Cost per km: " << carrier.getCost() << " BYN\n"
       << "Distance: " << carrier.getDistance() << " km\n"
       << "Travel time: " << carrier.calculateTime() << " h\n"
       << "Trip cost: " << carrier.calculateCost() << " BYN";
    return os;
}

std::istream& operator>>(std::istream& is, PassengerPerevozchik& carrier) {
    std::string name;
    double speed, cost, distance;
    
    std::cout << "Enter name: ";
    getline(is, name);
    std::cout << "Enter speed (km/h): ";
    is >> speed;
    std::cout << "Enter cost per km (BYN): ";
    is >> cost;
    std::cout << "Enter distance (km): ";
    is >> distance;
    is.ignore();
    
    carrier.setName(name);
    carrier.setSpeed(speed);
    carrier.setCost(cost);
    carrier.setDistance(distance);
    
    return is;
}