#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : value(other.value) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int raw) {
	value = raw << bit;
}

Fixed::Fixed(const float raw) {
	// value = raw << bit;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed&  Fixed::operator=(const Fixed& C) {
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &C)
		value = C.value;
	return (*this);
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return value;
}

void Fixed::setRawBits( int const raw) {
	std::cout << "setRawBits member fuction called" << std::endl;
	value = raw;
}

float	Fixed::toFloat( void ) const {
	return (value);
}

int	Fixed::toInt( void ) const {
	return (value);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << static_cast<double>(fixed.value) / (1 << fixed.bit);
	return (os);
}