#include <iostream>
#include <windows.h>
#include "../headers/interface.h"

void waitForAnyKey() {
    std::cout << "Нажмите Enter для продолжения...";
    std::cin.ignore();
    std::cin.get();
}

int main()
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    
    Interface<AirPlane> app;
    app.menu();
    
    return 0;
}