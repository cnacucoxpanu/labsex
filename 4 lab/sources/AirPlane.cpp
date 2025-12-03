#include "../headers/AirPlane.h"
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
        case 5: {
            double newTax;
            std::cout << "Новый аэропортовый сбор: ";
            std::cin >> newTax;
            setAirportTax(newTax);
            std::cout << "Параметр аэропортового сбора изменен!" << std::endl;
            break;
        }
        case 6: {
            double newHeight;
            std::cout << "Новая высота полета: ";
            std::cin >> newHeight;
            setFlightHeight(newHeight);
            std::cout << "Параметр высоты полета изменен!" << std::endl;
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
    
    std::cout << "\n=== Ввод данных самолета ===" << std::endl;
    std::cout << "Введите имя: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    
    std::cout << "Введите скорость (km/h): ";
    std::cin >> speed;
    std::cin.ignore(1000, '\n');
    
    std::cout << "Введите стоимость за км (BYN): ";
    std::cin >> cost;
    std::cin.ignore(1000, '\n');
    
    std::cout << "Введите расстояние (km): ";
    std::cin >> distance;
    std::cin.ignore(1000, '\n');
    
    std::cout << "Введите аэропортовый сбор (BYN): ";
    std::cin >> tax;
    std::cin.ignore(1000, '\n');
    
    std::cout << "Введите высоту полета (m): ";
    std::cin >> height;
    std::cin.ignore(1000, '\n');
    
    airplane.setName(name);
    airplane.setSpeed(speed);
    airplane.setCost(cost);
    airplane.setDistance(distance); 
    airplane.setAirportTax(tax);
    airplane.setFlightHeight(height);
    
    return is;
}