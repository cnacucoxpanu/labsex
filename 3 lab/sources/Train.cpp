#include "../headers/Train.h"
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
            int newWagons;
            std::cout << "Новое количество вагонов: ";
            std::cin >> newWagons;
            setWagonCount(newWagons);
            std::cout << "Параметр количества вагонов изменен!" << std::endl;
            break;
        }
        case 6: {
            std::string newClass;
            std::cout << "Новый класс комфорта: ";
            std::cin.ignore();
            std::getline(std::cin, newClass);
            setComfortClass(newClass);
            std::cout << "Параметр класса комфорта изменен!" << std::endl;
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
    
    std::cout << "Введите имя: ";
    if (!std::getline(is, name)) return is;
    
    std::cout << "Введите скорость (km/h): ";
    is >> speed;
    is.ignore(1000, '\n');
    
    std::cout << "Введите стоимость за км (BYN): ";
    is >> cost;
    is.ignore(1000, '\n');
    
    std::cout << "Введите расстояние (km): ";
    is >> distance;
    is.ignore(1000, '\n');
    
    std::cout << "Введите количество вагонов: ";
    is >> wagons;
    is.ignore(1000, '\n');
    
    std::cout << "Введите класс комфорта (luxury/coupe/platzkart): ";
    if (!std::getline(is, comfort)) return is;
    
    train.setName(name);
    train.setSpeed(speed);
    train.setCost(cost);
    train.setDistance(distance);
    train.setWagonCount(wagons);
    train.setComfortClass(comfort);
    
    return is;
}