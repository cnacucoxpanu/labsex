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
    os << "Название: " << name << "\n"
       << "Скорость: " << speed << " км/ч\n"
       << "Стоимость за км: " << cost << " руб.\n"
       << "Расстояние: " << distance << " км\n"
       << "Время в пути: " << calculateTime() << " ч\n"
       << "Стоимость поездки: " << calculateCost() << " руб.";
    return os;
}

std::istream& PassengerCarrier::input(std::istream& is) {
    std::cout << "Введите название: ";
    getline(is, name);
    std::cout << "Введите скорость (км/ч): ";
    is >> speed;
    std::cout << "Введите стоимость за км: ";
    is >> cost;
    std::cout << "Введите расстояние (км): ";
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