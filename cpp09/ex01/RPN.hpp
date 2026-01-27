#pragma once

#include <stack>
#include <string>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

class RPN {
    private:
        std::stack<double> operands;

        bool isOperator(const std::string& token) const;
        double applyOperator(const std::string& op, double left, double right) const;
    public:
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();
        void evaluate(const std::string& expression);
        double getResult() const;
};