#include "../headers/AirPlane.h"
#include "../headers/expInput.h"
#include <iostream>
#include <iomanip>

AirPlane::AirPlane() : PassengerPerevozchik(), airportTax(0), flightHeight(0) {}

AirPlane::AirPlane(const std::string& n, double s, double c, double d, double tax, double height)
    : PassengerPerevozchik(n, s, c, d), airportTax(tax), flightHeight(height) {}

void AirPlane::setAirportTax(double tax) {
    airportTax = tax;
}

double AirPlane::getAirportTax() const {
    return airportTax;
}

void AirPlane::setFlightHeight(double height) {
    flightHeight = height;
}

double AirPlane::getFlightHeight() const {
    return flightHeight;
}

double AirPlane::calculateCost() const {
    return (distance * cost) + airportTax;
}

double AirPlane::calculateTime() const {
    return (distance / speed) + 2.0;
}

void AirPlane::shapka() const {
    std::cout << std::setw(20) << std::left << "Name" 
              << std::setw(15) << std::left << "Speed" 
              << std::setw(15) << std::left << "Cost"
              << std::setw(15) << std::left << "Distance"
              << std::setw(15) << std::left << "Tax"
              << std::setw(15) << std::left << "Height"
              << std::setw(15) << std::left << "Time"
              << std::setw(15) << std::left << "Total" << std::endl;
    std::cout << std::string(140, '-') << std::endl;
}

void AirPlane::print() const {
    std::cout << std::setw(20) << std::left << getName() 
              << std::setw(15) << std::left << getSpeed() 
              << std::setw(15) << std::left << getCost()
              << std::setw(15) << std::left << getDistance()
              << std::setw(15) << std::left << airportTax
              << std::setw(15) << std::left << flightHeight
              << std::setw(15) << std::left << calculateTime()
              << std::setw(15) << std::left << calculateCost();
}

void AirPlane::setMenu() {
    int choice;
    ExpInput exp;
    do {
        std::cout << "\n=== Редактирование параметров самолета ===" << std::endl;
        std::cout << "1. Изменить имя (" << getName() << ")" << std::endl;
        std::cout << "2. Изменить скорость (" << getSpeed() << " км/ч)" << std::endl;
        std::cout << "3. Изменить стоимость (" << getCost() << " BYN/км)" << std::endl;
        std::cout << "4. Изменить расстояние (" << getDistance() << " км)" << std::endl;
        std::cout << "5. Изменить аэропортовый сбор (" << getAirportTax() << " BYN)" << std::endl;
        std::cout << "6. Изменить высоту полета (" << getFlightHeight() << " м)" << std::endl;
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
                    
                    double newSpeed = exp.isNumber<double>(newSpeedStr, 100.0, 1500.0);
                    setSpeed(newSpeed);
                    std::cout << "Параметр скорости изменен!" << std::endl;
                    success = true;
                }
                catch (const ExpInput& e) {
                    std::cout << "Ошибка ввода скорости: ";
                    e.printError();
                    std::cout << "Пожалуйста, введите скорость заново (100-1500 км/ч)." << std::endl;
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
                    
                    double newCost = exp.isNumber<double>(newCostStr, 0.1, 500.0);
                    setCost(newCost);
                    std::cout << "Параметр стоимости изменен!" << std::endl;
                    success = true;
                }
                catch (const ExpInput& e) {
                    std::cout << "Ошибка ввода стоимости: ";
                    e.printError();
                    std::cout << "Пожалуйста, введите стоимость заново (0.1-500 BYN/км)." << std::endl;
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
                    
                    double newDistance = exp.isNumber<double>(newDistanceStr, 50.0, 20000.0);
                    setDistance(newDistance);
                    std::cout << "Параметр расстояния изменен!" << std::endl;
                    success = true;
                }
                catch (const ExpInput& e) {
                    std::cout << "Ошибка ввода расстояния: ";
                    e.printError();
                    std::cout << "Пожалуйста, введите расстояние заново (50-20000 км)." << std::endl;
                }
            }
            break;
        }
        case 5: {
            bool success = false;
            while (!success) {
                try {
                    std::string newTaxStr;
                    std::cout << "Новый аэропортовый сбор: ";
                    std::getline(std::cin, newTaxStr);
                    
                    double newTax = exp.isNumber<double>(newTaxStr, 0.0, 5000.0);
                    setAirportTax(newTax);
                    std::cout << "Параметр аэропортового сбора изменен!" << std::endl;
                    success = true;
                }
                catch (const ExpInput& e) {
                    std::cout << "Ошибка ввода аэропортового сбора: ";
                    e.printError();
                    std::cout << "Пожалуйста, введите сбор заново (0-5000 BYN)." << std::endl;
                }
            }
            break;
        }
        case 6: {
            bool success = false;
            while (!success) {
                try {
                    std::string newHeightStr;
                    std::cout << "Новая высота полета: ";
                    std::getline(std::cin, newHeightStr);
                    
                    double newHeight = exp.isNumber<double>(newHeightStr, 1000.0, 15000.0);
                    setFlightHeight(newHeight);
                    std::cout << "Параметр высоты полета изменен!" << std::endl;
                    success = true;
                }
                catch (const ExpInput& e) {
                    std::cout << "Ошибка ввода высоты полета: ";
                    e.printError();
                    std::cout << "Пожалуйста, введите высоту заново (1000-15000 м)." << std::endl;
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

std::istream& operator>>(std::istream& is, AirPlane& airplane) {
    std::string name;
    double speed, cost, distance, tax, height;
    
    try {
        ExpInput exp;

        std::cout << "\n=== Ввод данных самолета ===" << std::endl;
        std::cout << "введите имя: ";
        std::getline(is, name);
        name = exp.isString(name);

        std::cout << "введите скорость (км/ч): ";
        std::string speedStr;
        std::getline(is, speedStr);
        speed = exp.isNumber<double>(speedStr, 100.0, 1500.0);
        
        std::cout << "введите стоимость за км (BYN): ";
        std::string costStr;
        std::getline(is, costStr);
        cost = exp.isNumber(costStr, 0.1, 500.0);

        std::cout << "введите расстояние (км): ";
        std::string distanceStr;
        std::getline(is, distanceStr);
        distance = exp.isNumber<double>(distanceStr, 50.0, 20000.0);

        std::cout << "введите аэропортовый сбор (BYN): ";
        std::string taxStr;
        std::getline(is, taxStr);
        tax = exp.isNumber<double>(taxStr, 0.0, 5000.0);

        std::cout << "введите высоту полета: ";
        std::string heightStr;
        std::getline(is, heightStr);
        height = exp.isNumber<double>(heightStr, 1000.0, 15000.0);

        airplane.setName(name);
        airplane.setCost(cost);
        airplane.setDistance(distance);
        airplane.setSpeed(speed);
        airplane.setAirportTax(tax);
        airplane.setFlightHeight(height);
    }
    catch (const ExpInput& e) {
        std::cerr << "ошибка ввода данных самолета: ";
        e.printError();
        throw;
    }

    return is;
}