#include "calculator.h"
#include <algorithm>

std::string::iterator Calculator::it = {};
std::string::iterator Calculator::begin = {};

double Calculator::number() {
    double number = 0;
    while(isdigit(*it)) {
        number = number * 10 + (*it++ - 48);
    }
    if(*it == '.') {
        ++it;
        double divider = 10;
        while(isdigit(*it)) {
            number += (*it++ - 48) / divider;
            divider *= 10;
        }
    }
    return number;
}

double Calculator::fact() {
    if(isdigit(*it)) {
        return number();
    }
    if(*it == '(') {
        ++it;
        double res = evaluate();
        ++it;
        return res;
    }
    if(*it == '-') {
        ++it;
        return -fact();
    }
    return 0.0;
}

double Calculator::term() {
    double res = fact();
    while(*it == '/' || *it == '*') {
        if(*it++ == '/') {
            res /= fact();
        }
        else {
            res *= fact();
        }
    }
    return res;
}

double Calculator::evaluate() {
    double res = term();
    while(*it == '-' || *it == '+') {
        if(*it++ == '-') {
            res -= term();
        }
        else {
            res += term();
        }
    }
    return res;
}

double Calculator::calculate(std::string _expression) {
    it = _expression.begin();
    begin = it;
    *(std::remove(it, _expression.end(), ' ')) = '\0';
    return evaluate();
}
