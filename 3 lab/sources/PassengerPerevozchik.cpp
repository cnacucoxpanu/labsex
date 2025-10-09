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


std::ostream& PassengerPerevozchik::output(std::ostream& os) const {
    os << "Name: " << name << "\n"
       << "Speed: " << speed << " km/h\n"
       << "Cost per km: " << cost << " BYN\n"
       << "Distance: " << distance << " km\n"
       << "Travel time: " << calculateTime() << " h\n"
       << "Trip cost: " << calculateCost() << " BYN";
    return os;
}

std::istream& PassengerPerevozchik::input(std::istream& is) {
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

PassengerPerevozchik& PassengerPerevozchik::operator=(const PassengerPerevozchik& other) {
    if(this != &other) {
        name = other.name;
        speed = other.speed;
        cost = other.cost;
        distance = other.distance;
    }
    return *this;
}

PassengerPerevozchik::~PassengerPerevozchik() {}

std::ostream& operator<<(std::ostream& os, const PassengerPerevozchik& carrier) {
    return carrier.output(os);
}

std::istream& operator>>(std::istream& is, PassengerPerevozchik& carrier) {
    return carrier.input(is);
}