#include "../headers/Train.h"
#include "../headers/expInput.h"
#include <iostream>
#include <iomanip>

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

void Train::shapka() const {
    std::cout << std::setw(20) << std::left << "Name" 
              << std::setw(15) << std::left << "Speed" 
              << std::setw(15) << std::left << "Cost"
              << std::setw(15) << std::left << "Distance"
              << std::setw(15) << std::left << "Wagons"
              << std::setw(15) << std::left << "Class"
              << std::setw(15) << std::left << "Time"
              << std::setw(15) << std::left << "Total" << std::endl;
    std::cout << std::string(140, '-') << std::endl;
}

void Train::print() const {
    std::cout << std::setw(20) << std::left << getName() 
              << std::setw(15) << std::left << getSpeed() 
              << std::setw(15) << std::left << getCost()
              << std::setw(15) << std::left << getDistance()
              << std::setw(15) << std::left << wagonCount
              << std::setw(15) << std::left << comfortClass
              << std::setw(15) << std::left << calculateTime()
              << std::setw(15) << std::left << calculateCost();
}

void Train::setMenu() {
    int choice;
    ExpInput exp;
    do {
        std::cout << "\n=== Редактирование параметров поезда ===" << std::endl;
        std::cout << "1. Изменить имя (" << getName() << ")" << std::endl;
        std::cout << "2. Изменить скорость (" << getSpeed() << " км/ч)" << std::endl;
        std::cout << "3. Изменить стоимость (" << getCost() << " BYN/км)" << std::endl;
        std::cout << "4. Изменить расстояние (" << getDistance() << " км)" << std::endl;
        std::cout << "5. Изменить количество вагонов (" << getWagonCount() << ")" << std::endl;
        std::cout << "6. Изменить класс комфорта (" << getComfortClass() << ")" << std::endl;
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
                    
                    double newCost = exp.isNumber<double>(newCostStr, 0.05, 100.0);
                    setCost(newCost);
                    std::cout << "Параметр стоимости изменен!" << std::endl;
                    success = true;
                }
                catch (const ExpInput& e) {
                    std::cout << "Ошибка ввода стоимости: ";
                    e.printError();
                    std::cout << "Пожалуйста, введите стоимость заново (0.05-100 BYN/км)." << std::endl;
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
                    std::string newWagonsStr;
                    std::cout << "Новое количество вагонов: ";
                    std::getline(std::cin, newWagonsStr);
                    
                    int newWagons = exp.isNumber<int>(newWagonsStr, 1, 50);
                    setWagonCount(newWagons);
                    std::cout << "Параметр количества вагонов изменен!" << std::endl;
                    success = true;
                }
                catch (const ExpInput& e) {
                    std::cout << "Ошибка ввода количества вагонов: ";
                    e.printError();
                    std::cout << "Пожалуйста, введите количество вагонов заново (1-50)." << std::endl;
                }
            }
            break;
        }
        case 6: {
            bool success = false;
            while (!success) {
                try {
                    std::string newClass;
                    std::cout << "Новый класс комфорта (luxury/coupe/platzkart): ";
                    std::getline(std::cin, newClass);
                    
                    newClass = exp.isComfortClass(newClass);
                    setComfortClass(newClass);
                    std::cout << "Параметр класса комфорта изменен!" << std::endl;
                    success = true;
                }
                catch (const ExpInput& e) {
                    std::cout << "Ошибка ввода класса комфорта: ";
                    e.printError();
                    std::cout << "Пожалуйста, введите класс заново (luxury/coupe/platzkart)." << std::endl;
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

std::istream& operator>>(std::istream& is, Train& train) {
    std::string name, comfort;
    double speed, cost, distance;
    int wagons;
    


    try {
        ExpInput exp;

        std::cout << "\n=== ввод данных поезда ===" << std::endl;
        std::cout << "введите имя: ";
        std::getline(is, name);
        name = exp.isString(name);

        std::cout << "введите скорость (км/ч): ";
        std::string speedStr;
        std::getline(is, speedStr);
        speed = exp.isNumber<double>(speedStr, 30.0, 400.0);

        std::cout << "введите стоимость за км (BYN): ";
        std::string costStr;
        std::getline(is, costStr);
        cost = exp.isNumber<double>(costStr, 0.05, 100.0);

        std::cout << "введите расстояние (км): ";
        std::string distanceStr;
        std::getline(is, distanceStr);
        distance = exp.isNumber<double>(distanceStr, 10.0, 5000.0);

        std::cout << "введите количество вагонов: ";
        std::string wagonStr;
        std::getline(is, wagonStr);
        wagons = exp.isNumber<int>(wagonStr, 1, 50);

        std::cout << "введите класс комфорта (luxury/coupe/platzkart): ";
        std::getline(is, comfort);
        if (comfort != "luxury" && comfort != "coupe" && comfort != "platzkart") {
            throw ExpInput("ComfortClass", ERROR_SPECIAL_CHARS);
        }
     

    train.setName(name);
    train.setSpeed(speed);
    train.setCost(cost);
    train.setDistance(distance);
    train.setWagonCount(wagons);
    train.setComfortClass(comfort);
    }
    catch (const ExpInput& e) {
        std::cerr << "ошибка ввода данных поезда: ";
        e.printError();
        throw;
    }
    
    return is;
}