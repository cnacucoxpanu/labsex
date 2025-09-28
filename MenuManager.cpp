// MenuManager.cpp
#include "MenuManager.h"
#include <iostream>

MenuManager::MenuManager() : running(true) {}

void MenuManager::run() {
    while (running) {
        display.showWelcome();
        display.showMainMenu();

        int choice;
        std::cout << "\nВыбор: ";
        std::cin >> choice;
        
        while (std::cin.get() != '\n') continue;

        handleMenuChoice(choice);

        if (running) {
            std::cout << "\nНажмите Enter...";
            std::cin.get();
        }
    }
}

void MenuManager::handleMenuChoice(int choice) {
    switch (choice) {
        case 1:
            performIntersection();
            break;
        case 2:
            display.showExitScreen();
            running = false;
            break;
        default:
            std::cout << "Неверно!" << std::endl;
            break;
    }
}

void MenuManager::performIntersection() {
    display.showIntersectionHeader();

    std::cout << "\nПервая строка:" << std::endl;
    StringOperations str1;
    str1.inputString();
    str1.displayString();

    std::cout << "\nВторая строка:" << std::endl;
    StringOperations str2;
    str2.inputString();
    str2.displayString();

    display.showResultsHeader();

    StringOperations result = str1.intersection(str2);
    std::cout << "\nРезультат: ";
    if (result.isEmpty()) {
        std::cout << "нет" << std::endl;
    } else {
        std::cout << result << std::endl;
    }

    std::cout << "\n=== ДЕМОНСТРАЦИЯ ОПЕРАЦИЙ ===" << std::endl;
    std::cout << "Конкатенация: " << str1 + str2 << std::endl;
    std::cout << "Строки равны: " << (str1 == str2 ? "да" : "нет") << std::endl;
    std::cout << "Первая < вторая: " << (str1 < str2 ? "да" : "нет") << std::endl;
    
    if (str1.getLength() > 0) {
        std::cout << "Первый символ: '" << str1[0] << "'" << std::endl;
    }
    if (str1.getLength() >= 3) {
        std::cout << "Подстрока (0-2): " << str1(0, 2) << std::endl;
    }
}