#include "Calculator.h"
#include <sstream>
#include <stdexcept>

Calculator::Calculator() {};

float Calculator::evaluate(const std::string& expr) {
    std::istringstream iss(expr);
    float result;
    iss >> result;

    char op;
    float num;

    while (iss >> op >> num) {
        result = applyOps(result, op, num);
    }

    return result;
}

float Calculator::applyOps(float lhs, char op, float rhs) {
    switch (op) {
        case '+': {return lhs + rhs;}
        case '-': {return lhs - rhs;}
        case '*': {return lhs*rhs;}
        case '/':
            if (rhs == 0) throw std::runtime_error("Can't divide by 0");
            return lhs / rhs;
        default:
            throw std::runtime_error("Invalid operator.");
    }
}
