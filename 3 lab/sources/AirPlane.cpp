#include "AirPlane.h"
#include <iostream>

AirPlane::AirPlane() : PassengerPerevozchik(), airportTax(0), flightHeight(0) {}

AirPlane::AirPlane(const std::string& n, double s, double c, double d, double tax, double height)
    : PassengerPerevozchik(n, s, c, d), airportTax(tax), flightHeight(height) {}

void AirPlane::setAirportTax(double tax) {
    airportTax = tax;
}

double AirPlane::getAirportTax() const {
    return airportTax;
}

void AirPlane::setFlightHeight(double height) {
    flightHeight = height;
}

double AirPlane::getFlightHeight() const {
    return flightHeight;
}

double AirPlane::calculateCost() const {
    return (distance * cost) + airportTax;
}

double AirPlane::calculateTime() const {
    return (distance / speed) + 2.0;
}

bool AirPlane::operator==(const AirPlane& other) const {
    return (PassengerPerevozchik::operator==(other) &&
            airportTax == other.airportTax &&
            flightHeight == other.flightHeight);
}

bool AirPlane::operator!=(const AirPlane& other) const {
    return !(*this == other);
}

AirPlane& AirPlane::operator=(const AirPlane& other) {
    if (this != &other) {
        PassengerPerevozchik::operator=(other);
        airportTax = other.airportTax;
        flightHeight = other.flightHeight;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const AirPlane& airplane) {
    os << "=== AIRPLANE ===\n"
       << "Name: " << airplane.getName() << "\n"
       << "Speed: " << airplane.getSpeed() << " km/h\n"
       << "Cost per km: " << airplane.getCost() << " BYN\n"
       << "Distance: " << airplane.getDistance() << " km\n"
       << "Airport tax: " << airplane.getAirportTax() << " BYN\n"
       << "Flight height: " << airplane.getFlightHeight() << " m\n"
       << "Total time (with registration): " << airplane.calculateTime() << " h\n"
       << "Total cost (with tax): " << airplane.calculateCost() << " BYN";
    return os;
}

std::istream& operator>>(std::istream& is, AirPlane& airplane) {
    std::string name;
    double speed, cost, distance, tax, height;
    
    std::cout << "Enter name: ";
    getline(is, name);
    std::cout << "Enter speed (km/h): ";
    is >> speed;
    std::cout << "Enter cost per km (BYN): ";
    is >> cost;
    std::cout << "Enter distance (km): ";
    is >> distance;
    std::cout << "Enter airport tax (BYN): ";
    is >> tax;
    std::cout << "Enter flight height (m): ";
    is >> height;
    is.ignore();
    
    airplane.setName(name);
    airplane.setSpeed(speed);
    airplane.setCost(cost);
    airplane.setDistance(distance);
    airplane.setAirportTax(tax);
    airplane.setFlightHeight(height);
    
    return is;
}