#include <iostream>
#include <vector>
#include "../headers/PassengerPerevozchik.h"
#include "../headers/AirPlane.h"
#include "../headers/Train.h"
#include "../headers/Car.h"
#include <windows.h>
using namespace std;

void clearInputBuffer() {
    cin.clear();
    cin.ignore(1000, '\n');
}

int main()
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    
    int size;
    
    //массив объектов AirPlane
    cout << "=== КЛАСС AirPlane ===" << endl;
    cout << "Сколько самолетов создать? ";
    cin >> size;
    clearInputBuffer();
    
    AirPlane* airplanes = new AirPlane[size];
    
    cout << "\n--- Ввод данных ---" << endl;
    for(int i = 0; i < size; i++)
    {
        cout << "Самолет " << i + 1 << ":" << endl;
        cin >> airplanes[i];
    }
    
    cout << "\n--- Таблица AirPlane ---" << endl;
    if (size > 0) {
        airplanes[0].shapka();
        for(int i = 0; i < size; i++)
        {
            airplanes[i].print();
            cout << endl;
        }
    }
    
    //массив объектов Train
    cout << "\n\n=== КЛАСС Train ===" << endl;
    cout << "Сколько поездов создать? ";
    cin >> size;
    clearInputBuffer();
    
    Train* trains = new Train[size];
    
    cout << "\n--- Ввод данных ---" << endl;
    for(int i = 0; i < size; i++)
    {
        cout << "Поезд " << i + 1 << ":" << endl;
        cin >> trains[i];
    }
    
    cout << "\n--- Таблица Train ---" << endl;
    if (size > 0) {
        trains[0].shapka();
        for(int i = 0; i < size; i++)
        {
            trains[i].print();
            cout << endl;
        }
    }
    
    //массив объектов Car
    cout << "\n\n=== КЛАСС Car ===" << endl;
    cout << "Сколько автомобилей создать? ";
    cin >> size;
    clearInputBuffer();
    
    Car* cars = new Car[size];
    
    cout << "\n--- Ввод данных ---" << endl;
    for(int i = 0; i < size; i++)
    {
        cout << "Автомобиль " << i + 1 << ":" << endl;
        cin >> cars[i];
    }
    
    cout << "\n--- Таблица Car ---" << endl;
    if (size > 0) {
        cars[0].shapka();
        for(int i = 0; i < size; i++)
        {
            cars[i].print();
            cout << endl;
        }
    }

    // Демонстрация виртуальных меню для объектов из массивов
    cout << "\n=== РЕДАКТИРОВАНИЕ ОБЪЕКТОВ ИЗ МАССИВОВ ===" << endl;

    if (size > 0) {
        // Редактирование первого самолета из массива
        cout << "\n--- Редактирование самолета из массива ---" << endl;
        airplanes[0].setMenu();

        // Редактирование первого поезда из массива
        cout << "\n--- Редактирование поезда из массива ---" << endl;
        trains[0].setMenu();

        // Редактирование первой машины из массива
        cout << "\n--- Редактирование автомобиля из массива ---" << endl;
        cars[0].setMenu();

        // Показываем измененные объекты
        cout << "\n--- Измененные объекты ---" << endl;
        airplanes[0].shapka();
        airplanes[0].print(); cout << endl;
        trains[0].shapka();
        trains[0].print(); cout << endl;
        cars[0].shapka();
        cars[0].print(); cout << endl;
    }

    // Демонстрация виртуальных меню для новых объектов
    cout << "\n=== ДЕМОНСТРАЦИЯ ВИРТУАЛЬНЫХ МЕНЮ ===" << endl;

    // Создаем новые объекты для демонстрации
    AirPlane demoPlane("DEMO-AIRPLANE", 800, 2.0, 1000, 50, 9000);
    Train demoTrain("DEMO-TRAIN", 150, 0.6, 300, 6, "coupe");
    Car demoCar("DEMO-CAR", 90, 0.4, 200, 4, 9.0);

    // Демонстрация меню самолета
    cout << "\n--- Меню изменения самолета ---" << endl;
    demoPlane.setMenu();

    // Демонстрация меню поезда
    cout << "\n--- Меню изменения поезда ---" << endl;
    demoTrain.setMenu();

    // Демонстрация меню автомобиля
    cout << "\n--- Меню изменения автомобиля ---" << endl;
    demoCar.setMenu();

    // Полиморфизм меню через базовый класс
    cout << "\n--- ПОЛИМОРФИЗМ МЕНЮ ---" << endl;
    vector<PassengerPerevozchik*> demoCarriers;
    demoCarriers.push_back(new AirPlane("POLY-AIR", 700, 1.8, 800, 40, 8000));
    demoCarriers.push_back(new Train("POLY-TRAIN", 120, 0.5, 250, 5, "platzkart"));
    demoCarriers.push_back(new Car("POLY-CAR", 80, 0.3, 150, 3, 8.0));

    for (auto carrier : demoCarriers) {
        carrier->setMenu();  // Виртуальный вызов!
    }

    // Демонстрация полиморфизма вывода
    cout << "\n=== ДЕМОНСТРАЦИЯ ПОЛИМОРФИЗМА ===" << endl;
    vector<PassengerPerevozchik*> carriers;
    carriers.push_back(new AirPlane("AIRBUS-A320", 850, 2.2, 1200, 60, 10000));
    carriers.push_back(new Train("SWALLOW", 160, 0.7, 400, 8, "luxury"));
    carriers.push_back(new Car("Mercedes", 100, 0.5, 250, 4, 10.0));
    
    // Выводим заголовок ОДИН раз
    if (!carriers.empty()) {
        carriers[0]->shapka();
    }
    
    for (size_t i = 0; i < carriers.size(); i++)
    {
        carriers[i]->print();
        cout << endl;
    }
    
    // Очистка памяти
    delete[] airplanes;
    delete[] trains;
    delete[] cars;
    
    for (auto carrier : carriers) {
        delete carrier;
    }
    
    for (auto carrier : demoCarriers) {
        delete carrier;
    }
    
    return 0;
}