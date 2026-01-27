#include <RPN.hpp>

RPN::RPN() {}
RPN::RPN(const RPN& other) : operands(other.operands) {}
RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        operands = other.operands;
    }
    return *this;
}
RPN::~RPN() {}

bool RPN::isOperator(const std::string& token) const {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

double RPN::applyOperator(const std::string& op, double left, double right) const {
    if (op == "+") return left + right;
    if (op == "-") return left - right;
    if (op == "*") return left * right;
    if (op == "/") {
        if (right == 0) throw std::runtime_error("Error: Division by zero.");
        return left / right;
    }
    throw std::runtime_error("Error: Unknown operator " + op);
}

void RPN::evaluate(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;
    while (iss >> token) {
        if (isOperator(token)) {
            if (operands.size() < 2)
                throw std::runtime_error("Error: Insufficient operands.");
            double right = operands.top(); operands.pop();
            double left = operands.top(); operands.pop();
            if (right > 9 || right < -9 || left > 9 || left < -9)
                throw std::runtime_error("Error");
            double result = applyOperator(token, left, right);
            operands.push(result);
        } else {
            char* end;
            double value = std::strtod(token.c_str(), &end);
            if (*end != '\0')
                throw std::runtime_error("Error");
            operands.push(value);
        }
    }
    if (operands.size() != 1)
        throw std::runtime_error("Error: The user input has too many values.");
}

double RPN::getResult() const {
    if (operands.empty())
        throw std::runtime_error("Error: No result available.");
    return operands.top();
}