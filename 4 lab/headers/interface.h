#ifndef INTERFACE_H
#define INTERFACE_H

#include "ochered_node.h"
#include "AirPlane.h"
#include "Train.h"
#include "Car.h"
#include <iostream>
#include <string>

template<class T>
class Interface
{
private:
    Ochered<T> ochered;

public:
    Interface(){};
    ~Interface() = default;

    void menu();
    void fun();
    void editElement(T &element);
    void sortBySpeed();
    void searchByName();
};
#include "../sources/interface.tpp"

#endif