#include "../headers/PassengerPerevozchik.h"
#include "../headers/expInput.h"
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
    ExpInput exp;
    do {
        std::cout << "\n=== Редактирование параметров перевозчика ===" << std::endl;
        std::cout << "1. Изменить имя (" << getName() << ")" << std::endl;
        std::cout << "2. Изменить скорость (" << getSpeed() << " км/ч)" << std::endl;
        std::cout << "3. Изменить стоимость (" << getCost() << " BYN/км)" << std::endl;
        std::cout << "4. Изменить расстояние (" << getDistance() << " км)" << std::endl;
        std::cout << "0. Назад" << std::endl;
        std::cout << "Выберите параметр для редактирования: ";
        
        std::string choiceStr;
        std::getline(std::cin, choiceStr);
        
        try {
            choice = std::stoi(choiceStr);
        }
        catch (...) {
            choice = -1;
        }

        switch (choice) {
        case 1: {
            bool success = false;
            while (!success) {
                try {
                    std::string newName;
                    std::cout << "Новое имя: ";
                    std::getline(std::cin, newName);
                    
                    newName = exp.isString(newName);
                    setName(newName);
                    std::cout << "Параметр имени изменен!" << std::endl;
                    success = true;
                }
                catch (const ExpInput& e) {
                    std::cout << "Ошибка ввода имени: ";
                    e.printError();
                    std::cout << "Пожалуйста, введите имя заново." << std::endl;
                }
            }
            break;
        }
        case 2: {
            bool success = false;
            while (!success) {
                try {
                    std::string newSpeedStr;
                    std::cout << "Новая скорость: ";
                    std::getline(std::cin, newSpeedStr);
                    
                    double newSpeed = exp.isNumber<double>(newSpeedStr, 1.0, 2000.0);
                    setSpeed(newSpeed);
                    std::cout << "Параметр скорости изменен!" << std::endl;
                    success = true;
                }
                catch (const ExpInput& e) {
                    std::cout << "Ошибка ввода скорости: ";
                    e.printError();
                    std::cout << "Пожалуйста, введите скорость заново (1-2000 км/ч)." << std::endl;
                }
            }
            break;
        }
        case 3: {
            bool success = false;
            while (!success) {
                try {
                    std::string newCostStr;
                    std::cout << "Новая стоимость: ";
                    std::getline(std::cin, newCostStr);
                    
                    double newCost = exp.isNumber<double>(newCostStr, 0.01, 1000.0);
                    setCost(newCost);
                    std::cout << "Параметр стоимости изменен!" << std::endl;
                    success = true;
                }
                catch (const ExpInput& e) {
                    std::cout << "Ошибка ввода стоимости: ";
                    e.printError();
                    std::cout << "Пожалуйста, введите стоимость заново (0.01-1000 BYN/км)." << std::endl;
                }
            }
            break;
        }
        case 4: {
            bool success = false;
            while (!success) {
                try {
                    std::string newDistanceStr;
                    std::cout << "Новое расстояние: ";
                    std::getline(std::cin, newDistanceStr);
                    
                    double newDistance = exp.isNumber<double>(newDistanceStr, 1.0, 50000.0);
                    setDistance(newDistance);
                    std::cout << "Параметр расстояния изменен!" << std::endl;
                    success = true;
                }
                catch (const ExpInput& e) {
                    std::cout << "Ошибка ввода расстояния: ";
                    e.printError();
                    std::cout << "Пожалуйста, введите расстояние заново (1-50000 км)." << std::endl;
                }
            }
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
    
    try {
        ExpInput exp;

        std::cout << "введите имя: ";
        std::getline(is, name);
        name = exp.isString(name);

        std::cout << "введите скорость (км/ч): ";
        std::string speedStr;
        std::getline(is, speedStr);
        speed = exp.isNumber<double>(speedStr, 1.0, 2000.0);

        std::cout << "введите стоимость за км (BYN): ";
        std::string costStr;
        std::getline(is, costStr);
        cost = exp.isNumber<double>(costStr, 0.01, 1000.0);

        std::cout << "введите расстояние (км): ";
        std::string distanceStr;
        std::getline(is, distanceStr);
        distance = exp.isNumber<double>(distanceStr, 1.0, 50000.0);

        carrier.setName(name);
        carrier.setCost(cost);
        carrier.setDistance(distance);
        carrier.setSpeed(speed);
    }
    catch (const ExpInput& e) {
        std::cerr << "ошибка ввода данных перевозчика: ";
        e.printError();
        throw;
    }
    return is;
}