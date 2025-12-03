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
    void setMenu() override;
    double calculateCost() const override;
    double calculateTime() const override;
    void shapka() const override;
    void print() const override;
    
    friend std::ostream& operator<<(std::ostream& os, const AirPlane& obj) {
        os << obj.getName();
        return os;
    }
};

std::istream& operator>>(std::istream& is, AirPlane& airplane);

#endif