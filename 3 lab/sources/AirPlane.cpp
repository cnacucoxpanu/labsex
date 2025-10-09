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
    return (distance / speed) + 2.0; // + время на регистрацию
}

std::ostream& AirPlane::output(std::ostream& os) const {
    os << "---AIRPLANE---\n";
    PassengerPerevozchik::output(os);
    os << "\nAirport tax: " << airportTax << " BYN\n"
       << "Flight height: " << flightHeight << " m\n"
       << "Total time (with registration): " << calculateTime() << " h\n"
       << "Total cost (with tax): " << calculateCost() << " BYN";
    return os;
}

std::istream& AirPlane::input(std::istream& is) {
    PassengerPerevozchik::input(is);
    std::cout << "Enter airport tax (BYN): ";
    is >> airportTax;
    std::cout << "Enter flight height (m): ";
    is >> flightHeight;
    is.ignore();
    return is;
}

AirPlane& AirPlane::operator=(const AirPlane& other) {
    if (this != &other) {
        PassengerPerevozchik::operator=(other);
        airportTax = other.airportTax;
        flightHeight = other.flightHeight;
    }
    return *this;
}