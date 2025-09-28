// MenuManager.h
#ifndef MENUMANAGER_H
#define MENUMANAGER_H

#include "StringOperations.h"
#include "DisplayManager.h"

class MenuManager {
private:
    bool running;
    DisplayManager display;

    void performIntersection();
    void handleMenuChoice(int choice);

public:
    MenuManager();
    void run();
};

#endif