#ifndef PASSENGERPEREVOZCHIK_H
#define PASSENGERPEREVOZCHIK_H

#include <iostream>
#include <string>
#include <iomanip>

class PassengerPerevozchik {
protected:
    std::string name;
    double speed;
    double cost;
    double distance;

public:
    PassengerPerevozchik();
    PassengerPerevozchik(const std::string& n, double s, double c, double d);
    
    void setName(const std::string& newName);
    std::string getName() const;
    void setSpeed(double newSpeed);
    double getSpeed() const;
    void setCost(double newCost);
    double getCost() const;
    void setDistance(double newDistance);
    double getDistance() const;
    
    virtual double calculateTime() const;
    virtual double calculateCost() const;
    virtual void shapka() const = 0;
    virtual void print() const;
    virtual void setMenu();
    virtual ~PassengerPerevozchik() {}
    
    friend std::ostream& operator<<(std::ostream& os, const PassengerPerevozchik& obj) {
        os << obj.name;
        return os;
    }
};

std::istream& operator>>(std::istream& is, PassengerPerevozchik& carrier);

#endif