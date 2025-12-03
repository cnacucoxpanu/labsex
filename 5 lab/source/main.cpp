#include <iostream>
#include <windows.h>
#include <limits>
#include "../headers/interface.h"

void waitForAnyKey() {
    std::cout << "Нажмите Enter для продолжения...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

int main()
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    
    // Устанавливаем обработку исключений для всего приложения
    try {
        Interface<AirPlane> app;
        app.menu();
    }
    catch (const std::exception& e) {
        std::cerr << "Критическая ошибка: " << e.what() << std::endl;
        std::cout << "Нажмите Enter для выхода...";
        std::cin.get();
    }
    catch (...) {
        std::cerr << "Неизвестная критическая ошибка!" << std::endl;
        std::cout << "Нажмите Enter для выхода...";
        std::cin.get();
    }
    
    return 0;
}