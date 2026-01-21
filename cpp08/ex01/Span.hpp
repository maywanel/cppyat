#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <exception>
#include <climits>

class NotFoundException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Value not found in container";
        }
};

class Span {
    private:
        std::vector<int> numbers;
        unsigned int maxSize;

    public:
        Span(unsigned int n);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int number);
        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;
};