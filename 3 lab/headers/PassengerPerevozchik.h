#ifndef PASSENGERPEREVOZCHIK_H
#define PASSENGERPEREVOZCHIK_H

#include <iostream>
#include <string>

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
    
    // Операторы сравнения
    bool operator==(const PassengerPerevozchik& other) const;
    bool operator!=(const PassengerPerevozchik& other) const;
    
    // Оператор присваивания
    PassengerPerevozchik& operator=(const PassengerPerevozchik& other);
    
    virtual ~PassengerPerevozchik() = default;
};

// Глобальные операторы ввода/вывода
std::ostream& operator<<(std::ostream& os, const PassengerPerevozchik& carrier);
std::istream& operator>>(std::istream& is, PassengerPerevozchik& carrier);

#endif