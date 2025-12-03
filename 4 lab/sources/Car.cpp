#include "../headers/Car.h"
#include <iostream>
#include <iomanip>

Car::Car() : PassengerPerevozchik(), passengerCapacity(0), fuelConsumption(0) {}

Car::Car(const std::string& n, double s, double c, double d, int capacity, double consumption) : 
PassengerPerevozchik(n,s,c,d), passengerCapacity(capacity), fuelConsumption(consumption) {}

void Car::setPassengerCapacity(int capacity) {
    passengerCapacity = capacity;
}

int Car::getPassengerCapacity() const {
    return passengerCapacity;
}

void Car::setFuelConsumption(double consumption) {
    fuelConsumption = consumption;
}

double Car::getFuelConsumption() const {
    return fuelConsumption;
}

double Car::calculateCost() const {
    double fuelCost = (distance / 100) * fuelConsumption * 2.0;
    return distance * cost + fuelCost;
}

double Car::calculateTime() const {
    return (distance / speed);
}

void Car::shapka() const {
    std::cout << std::setw(20) << std::left << "Name" 
              << std::setw(15) << std::left << "Speed" 
              << std::setw(15) << std::left << "Cost"
              << std::setw(15) << std::left << "Distance"
              << std::setw(15) << std::left << "Capacity"
              << std::setw(15) << std::left << "Fuel"
              << std::setw(15) << std::left << "Time"
              << std::setw(15) << std::left << "Total" << std::endl;
    std::cout << std::string(140, '-') << std::endl;
}

void Car::print() const {
    std::cout << std::setw(20) << std::left << getName() 
              << std::setw(15) << std::left << getSpeed() 
              << std::setw(15) << std::left << getCost()
              << std::setw(15) << std::left << getDistance()
              << std::setw(15) << std::left << passengerCapacity
              << std::setw(15) << std::left << fuelConsumption
              << std::setw(15) << std::left << calculateTime()
              << std::setw(15) << std::left << calculateCost();
}

void Car::setMenu() {
    int choice;
    do {
        std::cout << "\n=== Редактирование параметров автомобиля ===" << std::endl;
        std::cout << "1. Изменить имя (" << getName() << ")" << std::endl;
        std::cout << "2. Изменить скорость (" << getSpeed() << " км/ч)" << std::endl;
        std::cout << "3. Изменить стоимость (" << getCost() << " BYN/км)" << std::endl;
        std::cout << "4. Изменить расстояние (" << getDistance() << " км)" << std::endl;
        std::cout << "5. Изменить вместимость (" << getPassengerCapacity() << " чел)" << std::endl;
        std::cout << "6. Изменить расход топлива (" << getFuelConsumption() << " л/100км)" << std::endl;
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
            int newCapacity;
            std::cout << "Новая вместимость: ";
            std::cin >> newCapacity;
            setPassengerCapacity(newCapacity);
            std::cout << "Параметр вместимости изменен!" << std::endl;
            break;
        }
        case 6: {
            double newConsumption;
            std::cout << "Новый расход топлива: ";
            std::cin >> newConsumption;
            setFuelConsumption(newConsumption);
            std::cout << "Параметр расхода топлива изменен!" << std::endl;
            break;
        }
        case 0:
            break;
        default:
            std::cout << "Неверный выбор!" << std::endl;
        }
    } while (choice != 0);
}

std::istream& operator>>(std::istream& is, Car& car) {
    std::string name;
    double speed, cost, distance, consumption;
    int capacity;
    
    std::cout << "\n=== Ввод данных автомобиля ===" << std::endl;
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
    
    std::cout << "Введите вместимость: ";
    std::cin >> capacity;
    std::cin.ignore(1000, '\n');
    
    std::cout << "Введите расход топлива (l/100 km): ";
    std::cin >> consumption;
    std::cin.ignore(1000, '\n');
    
    car.setName(name);
    car.setSpeed(speed);
    car.setCost(cost);
    car.setDistance(distance);
    car.setPassengerCapacity(capacity);
    car.setFuelConsumption(consumption);
    
    return is;
}