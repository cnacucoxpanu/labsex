#ifndef AIRPLANE_H
#define AIRPLANE_H

#include "PassengerPerevozchik.h"

class AirPlane : public PassengerPerevozchik {
private:
    double airportTax;
    double flightHeight;

public:
    AirPlane();
    AirPlane(const std::string& n, double s, double c, double d, double tax, double height);

    void setAirportTax(double tax);
    double getAirportTax() const;
    void setFlightHeight(double height);
    double getFlightHeight() const;

    double calculateCost() const override;
    double calculateTime() const override;

    // Операторы сравнения
    bool operator==(const AirPlane& other) const;
    bool operator!=(const AirPlane& other) const;
    
    // Оператор присваивания
    AirPlane& operator=(const AirPlane& other);
};

#endif