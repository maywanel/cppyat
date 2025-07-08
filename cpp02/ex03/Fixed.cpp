#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) {
    std::cout << "Int constructor called" << std::endl;
    _fixedPointValue = n << _fractionalBits;
}

Fixed::Fixed(const float f) {
    std::cout << "Float constructor called" << std::endl;
    _fixedPointValue = roundf(f * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}


Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        _fixedPointValue = other._fixedPointValue;
    return *this;
}


int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return _fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    _fixedPointValue = raw;
}


float Fixed::toFloat() const {
    return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
}

int Fixed::toInt() const {
    return _fixedPointValue >> _fractionalBits;
}


bool Fixed::operator>(const Fixed& other) const {
    return _fixedPointValue > other._fixedPointValue;
}
bool Fixed::operator<(const Fixed& other) const {
    return _fixedPointValue < other._fixedPointValue;
}
bool Fixed::operator>=(const Fixed& other) const {
    return _fixedPointValue >= other._fixedPointValue;
}
bool Fixed::operator<=(const Fixed& other) const {
    return _fixedPointValue <= other._fixedPointValue;
}
bool Fixed::operator==(const Fixed& other) const {
    return _fixedPointValue == other._fixedPointValue;
}
bool Fixed::operator!=(const Fixed& other) const {
    return _fixedPointValue != other._fixedPointValue;
}


Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
    return Fixed(this->toFloat() / other.toFloat());
}


Fixed& Fixed::operator++() {
    _fixedPointValue++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    _fixedPointValue++;
    return tmp;
}

Fixed& Fixed::operator--() {
    _fixedPointValue--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    _fixedPointValue--;
    return tmp;
}


Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& out, const Fixed& value) {
    out << value.toFloat();
    return out;
}
