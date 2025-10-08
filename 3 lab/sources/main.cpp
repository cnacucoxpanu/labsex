#include <iostream>
#include <vector>
#include "PassengerCarrier.h"
#include "AirPlane.h"
#include "Train.h"
#include "Car.h"
#include <windows.h>

void demonstratePassengerCarrier() {
    std::cout << "---Base class demonstration---\n";
    PassengerCarrier carrier1("General transport", 60, 0.5, 300); // 0.5 BYN за км
    std::cout << carrier1 << "\n\n";

    PassengerCarrier carrier2;
    std::cout << "Enter data for base transport:\n";
    std::cin >> carrier2;
    std::cout << "\nResult:\n" << carrier2 << "\n\n";

    carrier1 = carrier2;
    std::cout << "After assignment carrier1 = carrier2\n" << carrier1 << "\n\n";
}

void demonstrateAirplane() {
    std::cout << "---Airplane class demonstration---\n";
    AirPlane airplane1("Boeing 737", 800, 2.5, 2000, 50, 10000); // 2.5 BYN за км, 50 BYN такса
    std::cout << airplane1 << "\n\n";
    
    AirPlane airplane2;
    std::cout << "Enter data for airplane:\n";
    std::cin >> airplane2;
    std::cout << "\nResult:\n" << airplane2 << "\n\n";
    
    // демо методов доступа
    airplane1.setAirportTax(60);
    airplane1.setFlightHeight(11000);
    std::cout << "After changes:\n";
    std::cout << "Airport tax: " << airplane1.getAirportTax() << " BYN\n";
    std::cout << "Flight height: " << airplane1.getFlightHeight() << " m\n\n";
}

void demonstrateTrain() {
    std::cout << "---Train class demonstration---\n";
    Train train1("Sapsan", 250, 0.8, 650, 10, "luxury"); // 0.8 BYN за км
    std::cout << train1 << "\n\n";
    
    Train train2;
    std::cout << "Enter data for train:\n";
    std::cin >> train2;
    std::cout << "\nResult:\n" << train2 << "\n\n";
    
    // демо методов доступа
    train1.setWagonCount(12);
    train1.setComfortClass("coupe");
    std::cout << "After changes:\n";
    std::cout << "Wagon count: " << train1.getWagonCount() << "\n";
    std::cout << "Comfort class: " << train1.getComfortClass() << "\n\n";
}

void demonstrateCar() {
    std::cout << "---Car class demonstration---\n";
    Car car1("Mercedes Sprinter", 90, 0.3, 500, 8, 8.5); // 0.3 BYN за км
    std::cout << car1 << "\n\n";
    
    Car car2;
    std::cout << "Enter data for car:\n";
    std::cin >> car2;
    std::cout << "\nResult:\n" << car2 << "\n\n";
    
    // демо методов доступа
    car1.setPassengerCapacity(6);
    car1.setFuelConsumption(10.5);
    std::cout << "After changes:\n";
    std::cout << "Passenger capacity: " << car1.getPassengerCapacity() << " passengers\n";
    std::cout << "Fuel consumption: " << car1.getFuelConsumption() << " l/100 km\n\n";
}

void demonstratePolymorphism() {
    std::cout << "--- Polymorphism demonstration ---\n";
    
    std::vector<PassengerCarrier*> carriers;
    
    carriers.push_back(new AirPlane("Belavia", 850, 2.0, 1500, 45, 9500));
    carriers.push_back(new Train("Minsk-Brest", 160, 0.6, 400, 8, "coupe"));
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
    demonstratePassengerCarrier();
    demonstrateAirplane();
    demonstrateTrain();
    demonstrateCar();
    demonstratePolymorphism();
    
    return 0;
}