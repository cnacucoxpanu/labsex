#include "Train.h"
#include <iostream>

Train::Train() : PassengerCarrier(), wagonCount(0), comfortClass("") {}

Train::Train(const std::string& n, double s, double c, double d, int wagons, const std::string& comfort)
    : PassengerCarrier(n, s, c, d), wagonCount(wagons), comfortClass(comfort) {}


    void Train::setWagonCount(int count) {
        wagonCount = count;
    }

    int Train::getWagonCount() const {
        return wagonCount;
    }

    void Train::setComfortClass(const std::string& comfort) {
    comfortClass = comfort;
    }

    std::string Train::getComfortClass() const {
        return comfortClass;
    }

    double Train::calculateCost() const {
         double multiplier = 1.0;
    if (comfortClass == "люкс") multiplier = 1.5;
    else if (comfortClass == "купе") multiplier = 1.2;
    else if (comfortClass == "плацкарт") multiplier = 1.0;
    
    return distance * cost * multiplier;
    }

    double Train::calculateTime() const {
        double stopTime = (distance / 100) * (5.00 / 60);
        return (distance / speed) + stopTime;
    }

    std::ostream& Train::output(std::ostream& os) const {
    os << "=== ПОЕЗД ===\n";
    PassengerCarrier::output(os);
    os << "\nКоличество вагонов: " << wagonCount << "\n"
       << "Класс комфорта: " << comfortClass << "\n"
       << "Общее время (с учетом остановок): " << calculateTime() << " ч\n"
       << "Общая стоимость (с учетом класса): " << calculateCost() << " руб.";
    return os;
}

std::istream& Train::input(std::istream& is) {
    PassengerCarrier::input(is);
    std::cout << "Введите количество вагонов: ";
    is >> wagonCount;
    is.ignore();
    std::cout << "Введите класс комфорта (люкс/купе/плацкарт): ";
    getline(is, comfortClass);
    return is;
}

Train& Train::operator=(const Train& other) {
    if (this != &other) {
        PassengerCarrier::operator=(other);
        wagonCount = other.wagonCount;
        comfortClass = other.comfortClass;
    }
    return *this;
}

