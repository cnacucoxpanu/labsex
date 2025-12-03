#ifndef EXPINPUT_H
#define EXPINPUT_H

#include "Exp.h"
#include <string>
#include <cctype>
#include <sstream>

#define ERROR_EMPTY_INPUT 1
#define ERROR_NON_ENGLISH 2
#define ERROR_SPECIAL_CHARS 3
#define ERROR_NUMBER_FORMAT 4
#define ERROR_NUMBER_RANGE 5

class ExpInput : public Exp
{
    char err[80];

public:
    ExpInput() : Exp()
    {
        err[0] = '\0';
    };
    ExpInput(const char *err, int code) : Exp(code, "Ошибка ввода")
    {
        strcpy_s(this->err, err);
    };
    ExpInput(const Exp &other) : Exp(other) {};
    ~ExpInput() = default;
    
    const char* getErrorType() const { return err; }
    
    void printError() const override {
        std::cerr << "Ошибка ввода [" << code << "][" << err << "]: " << message << std::endl;
    }
    
    // 1. Проверка числа
    template<typename T>
    T isNumber(const std::string& input, T minVal, T maxVal) {
        try {
            if (input.empty()) {
                throw ExpInput("EmptyNumber", ERROR_EMPTY_INPUT);
            }
            
            std::istringstream iss(input);
            T value;
            iss >> value;
            
            if (iss.fail() || !iss.eof()) {
                throw ExpInput("NumberFormat", ERROR_NUMBER_FORMAT);
            }
            
            if (value < minVal || value > maxVal) {
                throw ExpInput("NumberRange", ERROR_NUMBER_RANGE);
            }
            
            return value;
        }
        catch (const ExpInput& e) {
            throw;
        }
    }
    
    // 2. Проверка строки (английские символы, без цифр и спецсимволов)
    std::string isString(const std::string& input) {
        try {
            if (input.empty()) {
                throw ExpInput("EmptyText", ERROR_EMPTY_INPUT);
            }
            
            for (char c : input) {
                if (static_cast<unsigned char>(c) > 127) {
                    throw ExpInput("NonEnglish", ERROR_NON_ENGLISH);
                }
            }
            
            const std::string forbiddenChars = ",&?*#@!$%^()+=[]{};:\"<>/\\";
            
            for (char c : input) {
                if (std::isdigit(c)) {
                    throw ExpInput("DigitsNotAllowed", ERROR_SPECIAL_CHARS);
                }
                if (forbiddenChars.find(c) != std::string::npos) {
                    throw ExpInput("SpecialChars", ERROR_SPECIAL_CHARS);
                }
            }
            
            return input;
        }
        catch (const ExpInput& e) {
            throw;
        }
    }
    
    // 3. Проверка класса комфорта для поезда
    std::string isComfortClass(const std::string& input) {
        try {
            if (input.empty()) {
                throw ExpInput("EmptyComfort", ERROR_EMPTY_INPUT);
            }
            
            if (input != "luxury" && input != "coupe" && input != "platzkart") {
                throw ExpInput("InvalidComfort", ERROR_SPECIAL_CHARS);
            }
            
            return input;
        }
        catch (const ExpInput& e) {
            throw;
        }
    }
    
    // 4. Проверка булевого значения
    bool isBool(const std::string& input) {
        if (input == "true" || input == "1") return true;
        if (input == "false" || input == "0") return false;
        throw ExpInput("InvalidBool", ERROR_NUMBER_FORMAT);
    }
};

#endif