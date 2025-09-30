#ifndef PASSENGERCARRIER_H
#define PASSENGERCARRIER_H

#include <iostream>
#include <cstring>

class PassengerCarrier {
protected:
    std::string name;
    double speed;
    int cost; // за один километр
    double distance;


public:
    PassengerCarrier();
    PassengerCarrier(const std::string& n, double s, double c, double d);

    // методы
    void setName(const std::string& newName);
    std::string getName() const;
    void setSpeed(double newSpeed);
    double getSpeed() const;
    void setCost(double newCost);
    double getCost() const;
    void setDistance(double newDistance);
    double getDistance() const;


    //вирт ))
    virtual double calculateTime() const;
    virtual double calculateCost() const;

    //вирт ввод вывод
    virtual std::ostream& output(std::ostream& os) const;
    virtual std::istream& input(std::istream& is);

    PassengerCarrier& operator=(const PassengerCarrier& other);

    virtual ~PassengerCarrier();
};


    std::ostream& operator<<(std::ostream& os, const PassengerCarrier& carrier);
    std::istream& operator<<(std::istream& is, PassengerCarrier& carrier);


#endif