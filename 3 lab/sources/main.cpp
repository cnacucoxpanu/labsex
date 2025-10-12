#include <iostream>
#include <vector>
#include "PassengerPerevozchik.h"
#include "AirPlane.h"
#include "Train.h"
#include "Car.h"
#include <windows.h>

void demonstratePassengerPerevozchik() {
    std::cout << "---Base class demonstration---\n";
    PassengerPerevozchik carrier1("General transport", 60, 0.5, 300);
    std::cout << carrier1 << "\n\n";

    PassengerPerevozchik carrier2;
    std::cout << "Enter data for base transport:\n";
    std::cin >> carrier2;
    std::cout << "\nResult:\n" << carrier2 << "\n\n";

    carrier1 = carrier2;
    std::cout << "After assignment carrier1 = carrier2\n" << carrier1 << "\n\n";

    // Демонстрация операторов сравнения
    std::cout << "Comparison operators:\n";
    std::cout << "carrier1 == carrier2: " << (carrier1 == carrier2) << "\n";
    std::cout << "carrier1 != carrier2: " << (carrier1 != carrier2) << "\n\n";
}

void demonstrateAirplane() {
    std::cout << "---Airplane class demonstration---\n";
    AirPlane airplane1("Boeing 737", 800, 2.5, 2000, 50, 10000);
    std::cout << airplane1 << "\n\n";
    
    AirPlane airplane2;
    std::cout << "Enter data for airplane:\n";
    std::cin >> airplane2;
    std::cout << "\nResult:\n" << airplane2 << "\n\n";

    // Демонстрация операторов
    airplane1 = airplane2;
    std::cout << "After assignment:\n" << airplane1 << "\n\n";
    
    std::cout << "airplane1 == airplane2: " << (airplane1 == airplane2) << "\n";
    std::cout << "airplane1 != airplane2: " << (airplane1 != airplane2) << "\n\n";
}

void demonstrateTrain() {
    std::cout << "---Train class demonstration---\n";
    Train train1("Sapsan", 250, 0.8, 650, 10, "luxury");
    std::cout << train1 << "\n\n";
    
    Train train2;
    std::cout << "Enter data for train:\n";
    std::cin >> train2;
    std::cout << "\nResult:\n" << train2 << "\n\n";

    // Демонстрация операторов
    train1 = train2;
    std::cout << "After assignment:\n" << train1 << "\n\n";
    
    std::cout << "train1 == train2: " << (train1 == train2) << "\n";
    std::cout << "train1 != train2: " << (train1 != train2) << "\n\n";
}

void demonstrateCar() {
    std::cout << "---Car class demonstration---\n";
    Car car1("LAMBO", 90, 0.3, 500, 8, 8.5);
    std::cout << car1 << "\n\n";
    
    Car car2;
    std::cout << "Enter data for car:\n";
    std::cin >> car2;
    std::cout << "\nResult:\n" << car2 << "\n\n";

    // Демонстрация операторов
    car1 = car2;
    std::cout << "After assignment:\n" << car1 << "\n\n";
    
    std::cout << "car1 == car2: " << (car1 == car2) << "\n";
    std::cout << "car1 != car2: " << (car1 != car2) << "\n\n";
}

void demonstratePolymorphism() {
    std::cout << "--- Polymorphism demonstration ---\n";
    
    std::vector<PassengerPerevozchik*> carriers;
    
    carriers.push_back(new AirPlane("Belavia", 850, 2.0, 1500, 45, 9500));
    carriers.push_back(new Train("Minsk -> Saint-Petersburg", 160, 0.6, 400, 8, "coupe"));
    carriers.push_back(new Car("Minsk taxi", 80, 0.4, 300, 4, 9.0));
    
    for (size_t i = 0; i < carriers.size(); ++i) {
        std::cout << *carriers[i] << "\n\n";
    }
    
    for (auto carrier : carriers) {
        delete carrier;
    }
}

void setupConsole() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
}

int main() {
    setupConsole();
    demonstratePassengerPerevozchik();
    demonstrateAirplane();
    demonstrateTrain();
    demonstrateCar();
    demonstratePolymorphism();
    
    return 0;
}