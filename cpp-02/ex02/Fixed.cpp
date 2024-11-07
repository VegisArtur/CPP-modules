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
	value = static_cast<int>(round(raw * (1 << bit)));
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

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (value);
}

int Fixed::getBit(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (bit);
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member fuction called" << std::endl;
	value = raw;
}

float	Fixed::toFloat(void) const {
	return (static_cast<float>(value) / (1 << bit));
}

int	Fixed::toInt(void) const {
	return (value >> bit);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	// double float_value = static_cast<double>(fixed.getRawBits()) / (1 << fixed.getBit());
	os << fixed.toFloat();
	return (os);
}