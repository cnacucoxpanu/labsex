// StringOperations.cpp
#include "StringOperations.h"
#include <cstring>
#include <stdexcept>

StringOperations::StringOperations() : str(nullptr), length(0) {}

StringOperations::StringOperations(const char* input) : str(nullptr), length(0) {
    if (input) {
        length = std::strlen(input);
        str = new char[length + 1];
        std::strcpy(str, input);
    }
}

StringOperations::StringOperations(const StringOperations& other) : str(nullptr), length(other.length) {
    if (other.str) {
        str = new char[length + 1];
        std::strcpy(str, other.str);
    }
}

StringOperations::~StringOperations() {
    delete[] str;
}

StringOperations& StringOperations::operator=(const StringOperations& other) {
    if (this != &other) {
        delete[] str;
        length = other.length;
        if (other.str) {
            str = new char[length + 1];
            std::strcpy(str, other.str);
        } else {
            str = nullptr;
        }
    }
    return *this;
}

StringOperations StringOperations::operator+(const StringOperations& other) const {
    // Проверяем на nullptr
    const char* thisStr = str ? str : "";
    const char* otherStr = other.str ? other.str : "";
    
    int newLength = length + other.length;
    char* newStr = new char[newLength + 1];
    std::strcpy(newStr, thisStr);
    std::strcat(newStr, otherStr);
    return StringOperations(newStr);
}

StringOperations& StringOperations::operator+=(const StringOperations& other) {
    // Проверяем на nullptr
    const char* thisStr = str ? str : "";
    const char* otherStr = other.str ? other.str : "";
    
    int newLength = length + other.length;
    char* newStr = new char[newLength + 1];
    std::strcpy(newStr, thisStr);
    std::strcat(newStr, otherStr);
    delete[] str;
    str = newStr;
    length = newLength;
    return *this;
}

bool StringOperations::operator==(const StringOperations& other) const {
    // Проверяем на nullptr
    if (!str && !other.str) return true;
    if (!str || !other.str) return false;
    return std::strcmp(str, other.str) == 0;
}

bool StringOperations::operator<(const StringOperations& other) const {
    // Проверяем на nullptr
    if (!str && !other.str) return false;
    if (!str) return true;
    if (!other.str) return false;
    return std::strcmp(str, other.str) < 0;
}

bool StringOperations::operator>(const StringOperations& other) const {
    // Проверяем на nullptr
    if (!str && !other.str) return false;
    if (!str) return false;
    if (!other.str) return true;
    return std::strcmp(str, other.str) > 0;
}

char& StringOperations::operator[](int index) {
    if (!str || index < 0 || index >= length) {
        throw std::out_of_range("Index out of range");
    }
    return str[index];
}

StringOperations StringOperations::operator()(int start, int end) const {
    if (!str || start < 0 || start >= length) {
        return StringOperations();
    }
    if (end >= length) end = length - 1;
    if (start > end) return StringOperations();
    
    int subLength = end - start + 1;
    char* subStr = new char[subLength + 1];
    std::strncpy(subStr, str + start, subLength);
    subStr[subLength] = '\0';
    return StringOperations(subStr);
}

void StringOperations::inputString() {
    char buffer[80];
    std::cin.getline(buffer, 80);
    
    delete[] str;
    length = std::strlen(buffer);
    if (length > 0) {
        str = new char[length + 1];
        std::strcpy(str, buffer);
    } else {
        str = nullptr;
    }
}

void StringOperations::displayString() const {
    std::cout << "String: '";
    if (str) {
        std::cout << str;
    }
    std::cout << "'" << std::endl;
    std::cout << "Length: " << length << std::endl;
}

StringOperations StringOperations::intersection(const StringOperations& other) const {
    if (!str || !other.str || length == 0 || other.length == 0) {
        return StringOperations();
    }

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
    if (so.str) {
        os << so.str;
    }
    return os;
}