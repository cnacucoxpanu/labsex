// DisplayManager.cpp
#include "DisplayManager.h"
#include <iostream>

void DisplayManager::showWelcome() const {
    std::cout << "========================\n";
    std::cout << "   ЛАБОРАТОРНАЯ РАБОТА\n";
    std::cout << "========================\n";
}

void DisplayManager::showMainMenu() const {
    std::cout << "\n1. Пересечение\n";
    std::cout << "2. Выход\n";
}

void DisplayManager::showIntersectionHeader() const {
    std::cout << "\n=== ПЕРЕСЕЧЕНИЕ ===\n";
}

void DisplayManager::showResultsHeader() const {
    std::cout << "\n=== РЕЗУЛЬТАТ ===\n";
}

void DisplayManager::showExitScreen() const {
    std::cout << "\nВыход\n";
}