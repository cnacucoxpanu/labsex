#ifndef PassengerPerevozchik_H
#define PassengerPerevozchik_H

#include <iostream>
#include <cstring>

class PassengerPerevozchik {
protected:
    std::string name;
    double speed;
    double cost; // за один километр
    double distance;


public:
    PassengerPerevozchik();
    PassengerPerevozchik(const std::string& n, double s, double c, double d);

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

    PassengerPerevozchik& operator=(const PassengerPerevozchik& other);

    virtual ~PassengerPerevozchik();
};


    std::ostream& operator<<(std::ostream& os, const PassengerPerevozchik& carrier);
    std::istream& operator>>(std::istream& is, PassengerPerevozchik& carrier);


#endif