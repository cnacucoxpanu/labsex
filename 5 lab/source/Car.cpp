#include "../headers/Car.h"
#include "../headers/expInput.h"
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
    ExpInput exp;
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
                    
                    double newSpeed = exp.isNumber<double>(newSpeedStr, 30.0, 400.0);
                    setSpeed(newSpeed);
                    std::cout << "Параметр скорости изменен!" << std::endl;
                    success = true;
                }
                catch (const ExpInput& e) {
                    std::cout << "Ошибка ввода скорости: ";
                    e.printError();
                    std::cout << "Пожалуйста, введите скорость заново (30-400 км/ч)." << std::endl;
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
                    
                    double newCost = exp.isNumber<double>(newCostStr, 0.01, 50.0);
                    setCost(newCost);
                    std::cout << "Параметр стоимости изменен!" << std::endl;
                    success = true;
                }
                catch (const ExpInput& e) {
                    std::cout << "Ошибка ввода стоимости: ";
                    e.printError();
                    std::cout << "Пожалуйста, введите стоимость заново (0.01-50 BYN/км)." << std::endl;
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
                    
                    double newDistance = exp.isNumber<double>(newDistanceStr, 10.0, 5000.0);
                    setDistance(newDistance);
                    std::cout << "Параметр расстояния изменен!" << std::endl;
                    success = true;
                }
                catch (const ExpInput& e) {
                    std::cout << "Ошибка ввода расстояния: ";
                    e.printError();
                    std::cout << "Пожалуйста, введите расстояние заново (10-5000 км)." << std::endl;
                }
            }
            break;
        }
        case 5: {
            bool success = false;
            while (!success) {
                try {
                    std::string newCapacityStr;
                    std::cout << "Новая вместимость: ";
                    std::getline(std::cin, newCapacityStr);
                    
                    int newCapacity = exp.isNumber<int>(newCapacityStr, 1, 20);
                    setPassengerCapacity(newCapacity);
                    std::cout << "Параметр вместимости изменен!" << std::endl;
                    success = true;
                }
                catch (const ExpInput& e) {
                    std::cout << "Ошибка ввода вместимости: ";
                    e.printError();
                    std::cout << "Пожалуйста, введите вместимость заново (1-20 чел)." << std::endl;
                }
            }
            break;
        }
        case 6: {
            bool success = false;
            while (!success) {
                try {
                    std::string newConsumptionStr;
                    std::cout << "Новый расход топлива: ";
                    std::getline(std::cin, newConsumptionStr);
                    
                    double newConsumption = exp.isNumber<double>(newConsumptionStr, 1.0, 50.0);
                    setFuelConsumption(newConsumption);
                    std::cout << "Параметр расхода топлива изменен!" << std::endl;
                    success = true;
                }
                catch (const ExpInput& e) {
                    std::cout << "Ошибка ввода расхода топлива: ";
                    e.printError();
                    std::cout << "Пожалуйста, введите расход заново (1-50 л/100км)." << std::endl;
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

std::istream& operator>>(std::istream& is, Car& car) {
    std::string name;
    double speed, cost, distance, consumption;
    int capacity;
    
   try {
        ExpInput exp;

        std::cout << "\n=== ввод данных автомобиля ===" << std::endl;
        std::cout << "введите имя: ";
        std::getline(is, name);
        name = exp.isString(name);

        std::cout << "введите стоимость за км (BYN): ";
        std::string costStr;
        std::getline(is, costStr);
        cost = exp.isNumber<double>(costStr, 0.01, 50.0);

        std::cout << "введите скорость (км/ч): ";
        std::string speedStr;
        std::getline(is, speedStr);
        speed = exp.isNumber<double>(speedStr, 30.0, 400.0);

        std::cout << "введите расстояние (км): ";
        std::string distanceStr;
        std::getline(is, distanceStr);
        distance = exp.isNumber<double>(distanceStr, 10.0, 5000.0);
   
        std::cout << "введите вместимость: ";
        std::string capacityStr;
        std::getline(is, capacityStr);
        capacity = exp.isNumber<int>(capacityStr, 1, 20);

        std::cout << "введите расход топлива (1/100 km): ";
        std::string consumptionStr;
        std::getline(is, consumptionStr);
        consumption = exp.isNumber<double>(consumptionStr, 1.0, 50.0);
        

    car.setName(name);
    car.setSpeed(speed);
    car.setCost(cost);
    car.setDistance(distance);
    car.setPassengerCapacity(capacity);
    car.setFuelConsumption(consumption);
   }
   catch (const ExpInput& e) {
    std::cerr << "ошибка ввода данных автомобиля: ";
    e.printError();
    throw;
   }
    return is;
}