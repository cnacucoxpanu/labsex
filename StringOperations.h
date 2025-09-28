#define STRINGOPERATIONS_H
#ifndef STRINGOPERATIONS_H

#include <iostream>
#include <cstring>
#include <stdexcept>

class StringOperations {
    private:
        char *str;
        int length;

    public: 
        StringOperations();
        StringOperations(const char* input);
        StringOperations(const StringOperations& other);
        ~StirngOperations();

        StringOpearations& opeator=(const StringOperations& other);
        StringOpearations operator+(const StringOperations& other) const;
        StringOperations& operator+=(const StringOpeartions& other);
        bool operator==(const StringOperations& other) const;
        bool operator<(const StringOperations& other) const;
        bool operator>(const StringOperations& other) const;
        char& operator[](int index) const;
        StringOperatoins operator(int start, int end) const;

        void inputString();
        void displayString() const;
        StringOperatoins intersection(const StringOperations& other) const;
        
}



#endif