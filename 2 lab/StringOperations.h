#ifndef STRINGOPERATIONS_H
#define STRINGOPERATIONS_H

#include <iostream>

class StringOperations {
private:
    char* str;
    int length;

public:
    StringOperations();
    StringOperations(const char* input);
    StringOperations(const StringOperations& other);
    ~StringOperations();

    StringOperations& operator=(const StringOperations& other);
    StringOperations operator+(const StringOperations& other) const;
    StringOperations& operator+=(const StringOperations& other);
    bool operator==(const StringOperations& other) const;
    bool operator<(const StringOperations& other) const;
    bool operator>(const StringOperations& other) const;
    char& operator[](int index);
    StringOperations operator()(int start, int end) const;

    void inputString();
    void displayString() const;
    StringOperations intersection(const StringOperations& other) const;
    
    int getLength() const { return length; }
    bool isEmpty() const { return length == 0; }

    friend std::ostream& operator<<(std::ostream& os, const StringOperations& so);
    friend std::istream& operator>>(std::istream& is, StringOperations& so);
};

#endif