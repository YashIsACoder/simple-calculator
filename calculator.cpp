#include "Calculator.h"
#include <sstream>
#include <stdexcept>
#include <stack>
#include <cctype>

Calculator::Calculator() {}

float Calculator::applyOps(float lhs, char op, float rhs) {
    switch (op) {
        case '+': return lhs + rhs;
        case '-': return lhs - rhs;
        case '*': return lhs * rhs;
        case '/':
            if (rhs == 0) throw std::runtime_error("Can't divide by 0");
            return lhs / rhs;
        default:
            throw std::runtime_error("Invalid operator.");
    }
}

int Calculator::precedence(char op) {
    switch (op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        default:  return 0;
    }
}

float Calculator::evaluate(const std::string& expr) {
    std::istringstream iss(expr);
    std::stack<float> values;
    std::stack<char> ops;

    auto applyTop = [&]() {
        float rhs = values.top(); values.pop();
        float lhs = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(applyOps(lhs, op, rhs));
    };

    float num;
    char c;
    while (iss >> std::ws) {
        if (std::isdigit(iss.peek())) {
            iss >> num;
            values.push(num);
        } else {
            iss >> c;
            while (!ops.empty() && precedence(ops.top()) >= precedence(c)) {
                applyTop();
            }
            ops.push(c);
        }
    }

    while (!ops.empty()) {
        applyTop();
    }

    return values.top();
}
