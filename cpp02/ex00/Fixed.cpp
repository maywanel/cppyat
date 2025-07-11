#include "Fixed.hpp"

Fixed::Fixed() : _fixed_point(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
  std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy) {
  std::cout << "Copy constructor called" << std::endl;
  *this = copy;
}

Fixed &Fixed::operator=(const Fixed& copy) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &copy)
    _fixed_point = copy.getRawBits();
  return *this;
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _fixed_point;
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_fixed_point = raw;
}

