#include "StringOperations.h"
#include <cstring>
#include <stdexcept>

StringOperations::StringOperations() : str(nullptr), length(0) {}

StringOperations::StringOperations(const char* input) : str(nullptr), length(0) {
    if (input) {
        length = strlen(input);
        str = new char[length + 1];
        strcpy(str, input);
    }
}

StringOperations::StringOperations(const StringOperations& other) : str(nullptr), length(other.length) {
    if (other.str) {
        str = new char[length + 1];
        strcpy(str, other.str);
    }
}

StringOperations::~StringOperations() { delete[] str; }

StringOperations& StringOperations::operator=(const StringOperations& other) {
    if (this != &other) {
        delete[] str;
        length = other.length;
        str = other.str ? new char[length + 1] : nullptr;
        if (str) strcpy(str, other.str);
    }
    return *this;
}

StringOperations StringOperations::operator+(const StringOperations& other) const {
    const char* s1 = str ? str : "";
    const char* s2 = other.str ? other.str : "";
    
    char* newStr = new char[length + other.length + 1];
    strcpy(newStr, s1);
    strcat(newStr, s2);
    
    StringOperations result(newStr);
    delete[] newStr;
    return result;
}

StringOperations& StringOperations::operator+=(const StringOperations& other) {
    return *this = *this + other;
}

bool StringOperations::operator==(const StringOperations& other) const {
    if (!str && !other.str) return true;
    if (!str || !other.str) return false;
    return strcmp(str, other.str) == 0;
}

bool StringOperations::operator<(const StringOperations& other) const {
    if (!str) return other.str != nullptr;
    if (!other.str) return false;
    return strcmp(str, other.str) < 0;
}

bool StringOperations::operator>(const StringOperations& other) const {
    return other < *this;
}

char& StringOperations::operator[](int index) {
    if (index < 0 || index >= length) throw std::out_of_range("Index error");
    return str[index];
}

StringOperations StringOperations::operator()(int start, int end) const {
    if (!str || start < 0 || start >= length || start > end) 
        return StringOperations();
    if (end >= length) end = length - 1;
    
    int subLen = end - start + 1;
    char* subStr = new char[subLen + 1];
    strncpy(subStr, str + start, subLen);
    subStr[subLen] = '\0';
    
    StringOperations result(subStr);
    delete[] subStr;
    return result;
}

void StringOperations::inputString() {
    char buffer[80];
    std::cin.getline(buffer, 80);
    *this = StringOperations(buffer);
}

void StringOperations::displayString() const {
    std::cout << "String: '" << (str ? str : "") << "'\nLength: " << length << std::endl;
}

StringOperations StringOperations::intersection(const StringOperations& other) const {
    if (!str || !other.str) return StringOperations();
    
    char result[80] = "";
    char temp[80];
    strcpy(temp, str);
    
    char* word = strtok(temp, " ");
    while (word) {
        if (strstr(other.str, word) && !strstr(result, word)) {
            if (strlen(result) > 0) strcat(result, " ");
            strcat(result, word);
        }
        word = strtok(nullptr, " ");
    }
    return StringOperations(result);
}

std::ostream& operator<<(std::ostream& os, const StringOperations& so) {
    return os << (so.str ? so.str : "");
}

std::istream& operator>>(std::istream& is, StringOperations& so) {
    char buffer[80];
    is.getline(buffer, 80);
    so = StringOperations(buffer);
    return is;
}