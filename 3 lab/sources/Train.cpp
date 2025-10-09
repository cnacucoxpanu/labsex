#include "Train.h"
#include <iostream>

Train::Train() : PassengerPerevozchik(), wagonCount(0), comfortClass("") {}

Train::Train(const std::string& n, double s, double c, double d, int wagons, const std::string& comfort)
    : PassengerPerevozchik(n, s, c, d), wagonCount(wagons), comfortClass(comfort) {}


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
    if (comfortClass == "luxury") multiplier = 1.5;
    else if (comfortClass == "coupe") multiplier = 1.2;
    else if (comfortClass == "platzkart") multiplier = 1.0;
    
    return distance * cost * multiplier;
    }

    double Train::calculateTime() const {
        double stopTime = (distance / 100) * (5.00 / 60);
        return (distance / speed) + stopTime;
    }

    std::ostream& Train::output(std::ostream& os) const {
    os << "=== TRAIN ===\n";
    PassengerPerevozchik::output(os);
    os << "\nWagon count: " << wagonCount << "\n"
       << "Comfort class: " << comfortClass << "\n"
       << "Total time (with stops): " << calculateTime() << " h\n"
       << "Total cost (with class): " << calculateCost() << " BYN";
    return os;
}

std::istream& Train::input(std::istream& is) {
    PassengerPerevozchik::input(is);
    std::cout << "Enter wagon count: ";
    is >> wagonCount;
    is.ignore();
    std::cout << "Enter comfort class (luxury/coupe/platzkart): ";
    getline(is, comfortClass);
    return is;
}

Train& Train::operator=(const Train& other) {
    if (this != &other) {
        PassengerPerevozchik::operator=(other);
        wagonCount = other.wagonCount;
        comfortClass = other.comfortClass;
    }
    return *this;
}