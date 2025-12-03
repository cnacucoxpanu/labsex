#ifndef ERROR_H
#define ERROR_H

#include "../headers/expInput.h"
#include "../headers/exp.h"
#include <string>
#include <cctype>
#include <sstream>

#define ERROR_EMPTY_INPUT 1
#define ERROR_NON_ENGLISH 2
#define ERROR_SPECIAL_CHARS 3
#define ERROR_NUMBER_FORMAT 4
#define ERROR_NUMBER_RANGE 5

namespace ErrorFunctions {
    template <typename T> 
    T checkNumber(const std::string& input, T minVal, T maxVal) {
        try {
            if (input.empty()) {
                throw Exp_Input(ERROR_EMPTY_INPUT, "пустой ввод числа", "EmptyNumber");
            }

            std::istringstream iss(input);
            T value;
            iss >> value;

            if (iss.fail() || !iss.eof()) {
                throw Exp_Input(ERROR_NUMBER_FORMAT, "некорректный числовой формат", "NumberFormat");
            }

            if (value < minVal || value > maxVal) {
                throw Exp_Input(ERROR_NUMBER_RANGE, ("число вне диапазона [" + std::to_string(minVal) + " - " + std::to_string(maxVal) + "]").c_str(), "NumberRange");
            }
            return value;
        }
        catch (const Exp_Input& e) {
            throw; // Перебрасываем исключение дальше
        }
    }

    std::string checkEnglishText(const std::string& input) {
        try {
            if (input.empty()) {
                throw Exp_Input(ERROR_EMPTY_INPUT, "пустой ввод текста", "EmptyText");
            }
            
            for (char c : input) {
                if (static_cast<unsigned char>(c) > 127) {
                    throw Exp_Input(ERROR_NON_ENGLISH, "используйте только английские символы", "NonEnglish");
                }
            }
            return input;
        }
        catch (const Exp_Input& e) {
            throw;
        }
    }

    std::string checkSimpleString(const std::string& input) {
        try {
            if (input.empty()) {
                throw Exp_Input(ERROR_EMPTY_INPUT, "пустой ввод строки", "EmptyString");
            }
            
            const std::string forbiddenChars = ",&?*#@!$%^()+=[]{};:\"<>/\\";

            for (char c : input) {
                if (std::isdigit(c)) {
                    throw Exp_Input(ERROR_SPECIAL_CHARS, "цифры не допускаются в этом поле", "DigitsNotAllowed");
                }
                if (forbiddenChars.find(c) != std::string::npos) {
                    throw Exp_Input(ERROR_SPECIAL_CHARS, "запрещенные символы в строке", "SpecialChars");
                }
            }
            
            return checkEnglishText(input);
        }
        catch (const Exp_Input& e) {
            throw;
        }
    }
}

#endif