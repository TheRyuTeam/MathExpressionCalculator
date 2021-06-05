#pragma once
#include <string>

struct Calculator
{
private:
    static std::string::iterator it;
    static std::string::iterator begin;

    static double number();
    static double fact();
    static double term();
    static double evaluate();

public:
    static double calculate(std::string _expression);
};