#include "../headers/PassengerPerevozchik.h"
#include <iostream>
#include <limits>

PassengerPerevozchik::PassengerPerevozchik() : name(""), speed(0), cost(0), distance(0) {}

PassengerPerevozchik::PassengerPerevozchik(const std::string& n, double s, double c, double d) 
: name(n), speed(s), cost(c), distance(d) {}

void PassengerPerevozchik::setName(const std::string& newName) {
    name = newName;
}

std::string PassengerPerevozchik::getName() const {
    return name;
}

void PassengerPerevozchik::setSpeed(double newSpeed) {
    speed = newSpeed;
}

double PassengerPerevozchik::getSpeed() const {
    return speed;
}

void PassengerPerevozchik::setCost(double newCost) {
    cost = newCost;
}

double PassengerPerevozchik::getCost() const {
    return cost;
}

void PassengerPerevozchik::setDistance(double newDistance) {
    distance = newDistance;
}

double PassengerPerevozchik::getDistance() const {
    return distance;
}

double PassengerPerevozchik::calculateTime() const {
    return distance / speed;
}

double PassengerPerevozchik::calculateCost() const {
    return distance * cost;
}

void PassengerPerevozchik::setMenu() {
    int choice;
    do {
        std::cout << "\n=== Редактирование параметров перевозчика ===" << std::endl;
        std::cout << "1. Изменить имя (" << getName() << ")" << std::endl;
        std::cout << "2. Изменить скорость (" << getSpeed() << " км/ч)" << std::endl;
        std::cout << "3. Изменить стоимость (" << getCost() << " BYN/км)" << std::endl;
        std::cout << "4. Изменить расстояние (" << getDistance() << " км)" << std::endl;
        std::cout << "0. Назад" << std::endl;
        std::cout << "Выберите параметр для редактирования: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string newName;
            std::cout << "Новое имя: ";
            std::cin.ignore();
            std::getline(std::cin, newName);
            setName(newName);
            std::cout << "Параметр имени изменен!" << std::endl;
            break;
        }
        case 2: {
            double newSpeed;
            std::cout << "Новая скорость: ";
            std::cin >> newSpeed;
            setSpeed(newSpeed);
            std::cout << "Параметр скорости изменен!" << std::endl;
            break;
        }
        case 3: {
            double newCost;
            std::cout << "Новая стоимость: ";
            std::cin >> newCost;
            setCost(newCost);
            std::cout << "Параметр стоимости изменен!" << std::endl;
            break;
        }
        case 4: {
            double newDistance;
            std::cout << "Новое расстояние: ";
            std::cin >> newDistance;
            setDistance(newDistance);
            std::cout << "Параметр расстояния изменен!" << std::endl;
            break;
        }
        case 0:
            break;
        default:
            std::cout << "Неверный выбор!" << std::endl;
        }
    } while (choice != 0);
}

void PassengerPerevozchik::print() const {
    std::cout << std::setw(20) << std::left << name 
              << std::setw(15) << std::left << speed 
              << std::setw(15) << std::left << cost
              << std::setw(15) << std::left << distance
              << std::setw(15) << std::left << calculateTime()
              << std::setw(15) << std::left << calculateCost();
}

std::istream& operator>>(std::istream& is, PassengerPerevozchik& carrier) {
    std::string name;
    double speed, cost, distance;
    
    std::cout << "Введите имя: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    
    std::cout << "Введите скорость (km/h): ";
    std::cin >> speed;
    
    std::cout << "Введите стоимость за км (BYN): ";
    std::cin >> cost;
    
    std::cout << "Введите расстояние (km): ";
    std::cin >> distance;
    
    carrier.setName(name);
    carrier.setSpeed(speed);
    carrier.setCost(cost);
    carrier.setDistance(distance);
    
    return is;
}