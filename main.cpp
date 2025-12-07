#include <iostream>
#include "Calculator.h"

int main() {
    Calculator calc;

    std::cout << "Enter expression: ";
    std::string expr;
    std::getline(std::cin, expr);

    try {
        float result = calc.evaluate(expr);
        std::cout << "Result: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
