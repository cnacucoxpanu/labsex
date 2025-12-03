#ifndef EXP_H
#define EXP_H

#include <iostream>
#include <cstring>

class Exp
{
protected:
    int code;
    char message[80];

public:
    Exp()
    {
        code = 0;
        message[0] = '\0';
    }
    Exp(int code, const char *message)
    {
        this->code = code;
        strcpy_s(this->message, message);
    }
    Exp(const Exp &other)
    {
        code = other.code;
        strcpy_s(message, other.message);
    }
    ~Exp() = default;
    
    int getCode() const { return code; }
    const char* getMessage() const { return message; }
    
    virtual void printError() const {
        std::cerr << "Ошибка [" << code << "]: " << message << std::endl;
    }
};

#endif