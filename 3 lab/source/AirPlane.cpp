#include "AirPlane.h"
#include <iostream>

AirPlane::AirPlane() : PassengerCarrier(), airportTax(0), flightHeight(0) {}

AirPlane::AirPlane(const std::string& n, double s, double c, double d, double tax, double height)
    : PassengerCarrier(n, s, c, d), airportTax(tax), flightHeight(height) {}

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
    os << "=== САМОЛЕТ ===\n";
    PassengerCarrier::output(os);
    os << "\nАэропортовый сбор: " << airportTax << " руб.\n"
       << "Высота полета: " << flightHeight << " м\n"
       << "Общее время (с учетом регистрации): " << calculateTime() << " ч\n"
       << "Общая стоимость (с учетом сбора): " << calculateCost() << " руб.";
    return os;
}

std::istream& AirPlane::input(std::istream& is) {
    PassengerCarrier::input(is);
    std::cout << "Введите аэропортовый сбор: ";
    is >> airportTax;
    std::cout << "Введите высоту полета (м): ";
    is >> flightHeight;
    is.ignore();
    return is;
}

AirPlane& AirPlane::operator=(const AirPlane& other) {
    if (this != &other) {
        PassengerCarrier::operator=(other);
        airportTax = other.airportTax;
        flightHeight = other.flightHeight;
    }
    return *this;
}