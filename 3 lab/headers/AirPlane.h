#ifndef AIRPLANE_H
#define AIRPLANE_H

#include "PassengerPerevozchik.h"

class AirPlane : public PassengerPerevozchik {
private:
    double airportTax; // сбор
    double flightHeight;   // высота полета

public:
    AirPlane();
    AirPlane(const std::string& n, double s, double c, double d, double tax, double height);

    void setAirportTax(double tax);
    double getAirportTax() const;
    void setFlightHeight(double height);
    double getFlightHeight() const;


    double calculateCost() const override;
    double calculateTime() const override;

    std::ostream& output(std::ostream& os) const override;
    std::istream& input(std::istream& is) override;

    AirPlane& operator=(const AirPlane& other);
};


#endif