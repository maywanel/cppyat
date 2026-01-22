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

        template <typename T>
        void addNumber(T begin, T end) {
            if (std::distance(begin, end) > static_cast<long>(maxSize - numbers.size()))
                throw std::out_of_range("Cannot add range: not enough space in Span");
            numbers.insert(numbers.end(), begin, end);
        }

        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;
};
