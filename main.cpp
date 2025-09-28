// main.cpp
#include "StringOperations.h"
#include <iostream>

int main() {
    std::cout << "=== CONSTRUCTORS TEST ===" << std::endl;
    StringOperations str1;
    StringOperations str2("Hello World");
    StringOperations str3 = str2;
    
    std::cout << "str1 (default): "; str1.displayString();
    std::cout << "str2 (with param): "; str2.displayString();
    std::cout << "str3 (copy of str2): "; str3.displayString();

    std::cout << "\n=== METHODS TEST ===" << std::endl;
    std::cout << "Enter first string for intersection: ";
    StringOperations str4;
    str4.inputString();
    
    std::cout << "Enter second string for intersection: ";
    StringOperations str5;
    str5.inputString();
    
    std::cout << "Intersection result: ";
    StringOperations intersectionResult = str4.intersection(str5);
    intersectionResult.displayString();

    std::cout << "\n=== OPERATORS TEST ===" << std::endl;
    StringOperations a("Hello");
    StringOperations b("World");
    
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "a + b = " << a + b << std::endl;
    std::cout << "a == b: " << (a == b ? "yes" : "no") << std::endl;
    std::cout << "a < b: " << (a < b ? "yes" : "no") << std::endl;
    std::cout << "a > b: " << (a > b ? "yes" : "no") << std::endl;
    
    if (a.getLength() > 0) {
        std::cout << "a[0] = '" << a[0] << "'" << std::endl;
    }
    
    if (a.getLength() >= 4) {
        std::cout << "a(0, 3) = " << a(0, 3) << std::endl;
    }
    
    a += b;
    std::cout << "a += b: " << a << std::endl;

    std::cout << "\nPress Enter to exit...";
    std::cin.get();
    return 0;
}