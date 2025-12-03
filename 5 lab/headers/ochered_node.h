#ifndef OCHERED_NODE_H
#define OCHERED_NODE_H

#include <iostream>

template <typename T>
class Ochered_node {
public:
    T data;
    Ochered_node<T>* next;
    Ochered_node<T>* prev;

    Ochered_node(T value) : data(value), next(nullptr), prev(nullptr) {}
    
    T& getData() { return data; }
    const T& getData() const { return data; }
};

template <typename T>
class Ochered {
private:
    Ochered_node<T>* head;
    Ochered_node<T>* tail;
    int size;

public:
    Ochered();
    ~Ochered();
    
    void push(const T& value);
    bool pop();
    void print() const;
    
    template <typename Predicate>
    Ochered_node<T>* search(Predicate pred) const;
    
    template <typename Compare>
    void sort(Compare comp);
    
    bool isEmpty() const;
    T& getFront();
    const T& getFront() const;
    int getSize() const;
};

// Включаем реализацию
#include "../source/ochered_node.tpp"

#endif