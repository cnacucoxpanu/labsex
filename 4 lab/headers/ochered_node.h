#ifndef OCHERED_NODE_H
#define OCHERED_NODE_H

#include <iostream>

class AirPlane;
class Train;
class Car;

template <typename T>
class Ochered;

template <typename T>
class Ochered_node {
    friend class Ochered<T>;

    T data;
    Ochered_node<T>* next;  // указатель на СЛЕДУЮЩИЙ узел
    Ochered_node<T>* prev;  // указатель на ПРЕДЫДУЩИЙ узел

public:
    Ochered_node(T value) : data(value), next(nullptr), prev(nullptr) {}
    
    T& getData() { return data; }
    const T& getData() const { return data; }
};

template <typename T>
class Ochered {
    Ochered_node<T>* head;  // указатель на ПЕРВЫЙ элемент (голова очереди)
    Ochered_node<T>* tail;  // указатель на ПОСЛЕДНИЙ элемент (хвост очереди)
    int size;               // количество элементов в очереди

public:
    Ochered();
    ~Ochered();
    
    void push(const T& value);    // добавить элемент в КОНЕЦ очереди
    bool pop();                   // удалить элемент из НАЧАЛА очереди
    void print() const;           // вывести все элементы очереди
    
    template <typename Predicate>
    Ochered_node<T>* search(Predicate pred) const;  // поиск элемента по условию
    
    template <typename Compare>
    void sort(Compare comp);      // сортировка очереди
    
    bool isEmpty() const;         // проверка на пустоту
    T& getFront();                // получить ПЕРВЫЙ элемент (без удаления)
    const T& getFront() const;
    int getSize() const;          // получить размер очереди
};

#include "../sources/ochered_node.tpp"

#endif