#include <windows.h>
#include "MenuManager.h"

int main() {
    SetConsoleOutputCP(65001); // UTF-8
    SetConsoleCP(65001); // UTF-8
    
    MenuManager menu;
    menu.run();
    return 0;
}