#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>

class Calculator {
public:
    Calculator();
    float evaluate(const std::string& expr);

private:
    float applyOps(float lhs, char op, float rhs);
    int precedence(char op);
};

#endif
