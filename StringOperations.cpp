// StringOperations.cpp
#include "StringOperations.h"
#include <cstring>
#include <stdexcept>

StringOperations::StringOperations() : str(nullptr), length(0) {
    str = new char[1];
    str[0] = '\0';
}

StringOperations::StringOperations(const char* input) : str(nullptr), length(0) {
    if (input) {
        length = std::strlen(input);
        str = new char[length + 1];
        std::strcpy(str, input);
    } else {
        str = new char[1];
        str[0] = '\0';
    }
}

StringOperations::StringOperations(const StringOperations& other) : str(nullptr), length(other.length) {
    str = new char[length + 1];
    std::strcpy(str, other.str);
}

StringOperations::~StringOperations() {
    delete[] str;
}

StringOperations& StringOperations::operator=(const StringOperations& other) {
    if (this != &other) {
        delete[] str;
        length = other.length;
        str = new char[length + 1];
        std::strcpy(str, other.str);
    }
    return *this;
}

StringOperations StringOperations::operator+(const StringOperations& other) const {
    char* newStr = new char[length + other.length + 1];
    std::strcpy(newStr, str);
    std::strcat(newStr, other.str);
    return StringOperations(newStr);
}

StringOperations& StringOperations::operator+=(const StringOperations& other) {
    char* newStr = new char[length + other.length + 1];
    std::strcpy(newStr, str);
    std::strcat(newStr, other.str);
    delete[] str;
    str = newStr;
    length += other.length;
    return *this;
}

bool StringOperations::operator==(const StringOperations& other) const {
    return std::strcmp(str, other.str) == 0;
}

bool StringOperations::operator<(const StringOperations& other) const {
    return std::strcmp(str, other.str) < 0;
}

bool StringOperations::operator>(const StringOperations& other) const {
    return std::strcmp(str, other.str) > 0;
}

char& StringOperations::operator[](int index) {
    if (index < 0 || index >= length) {
        throw std::out_of_range("Index out of range");
    }
    return str[index];
}

const char& StringOperations::operator[](int index) const {
    if (index < 0 || index >= length) {
        throw std::out_of_range("Index out of range");
    }
    return str[index];
}

StringOperations StringOperations::operator()(int start, int end) const {
    if (start < 0) start = 0;
    if (end >= length) end = length - 1;
    if (start > end) return StringOperations();
    
    int subLength = end - start + 1;
    char* subStr = new char[subLength + 1];
    std::strncpy(subStr, str + start, subLength);
    subStr[subLength] = '\0';
    return StringOperations(subStr);
}

void StringOperations::inputString() {
    std::cout << "Введите строку: ";
    
    char buffer[80];
    std::cin.getline(buffer, 80);
    
    delete[] str;
    length = std::strlen(buffer);
    str = new char[length + 1];
    std::strcpy(str, buffer);
}

void StringOperations::displayString() const {
    std::cout << "Строка: '" << str << "'" << std::endl;
    std::cout << "Длина: " << length << std::endl;
}

StringOperations StringOperations::intersection(const StringOperations& other) const {
    if (isEmpty() || other.isEmpty()) return StringOperations();

    char result[80] = "";
    char temp[80];
    std::strcpy(temp, str);
    
    char* word = std::strtok(temp, " ");
    while (word) {
        if (std::strstr(other.str, word) && !std::strstr(result, word)) {
            if (std::strlen(result) > 0) std::strcat(result, " ");
            std::strcat(result, word);
        }
        word = std::strtok(nullptr, " ");
    }
    return StringOperations(result);
}

std::ostream& operator<<(std::ostream& os, const StringOperations& so) {
    return os << so.str;
}