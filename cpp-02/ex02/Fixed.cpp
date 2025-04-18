#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : value(0) {
}

Fixed::Fixed(const Fixed& other) : value(other.value) {
}

Fixed::Fixed(const int raw) {
	value = raw << bit;
}

Fixed::Fixed(const float raw) {
	value = static_cast<int>(round(raw * (1 << bit)));
}

Fixed::~Fixed() {
}

Fixed&  Fixed::operator=(const Fixed& C) {
	if (this != &C)
		value = C.value;
	return (*this);
}

int Fixed::getRawBits(void) const {
	return (value);
}

int Fixed::getBit(void) const {
	return (bit);
}

void Fixed::setRawBits(int const raw) {
	value = raw;
}

float	Fixed::toFloat(void) const {
	return (static_cast<float>(value) / (1 << bit));
}

int	Fixed::toInt(void) const {
	return (value >> bit);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return (os);
}
bool	Fixed::operator>(const Fixed& other) const	{
	return (this->value > other.value);
}

bool	Fixed::operator>=(const Fixed& other) const	{
	return (this->value >= other.value);
}

bool	Fixed::operator<(const Fixed& other) const	{
	return (this->value < other.value);
}

bool	Fixed::operator<=(const Fixed& other) const	{
	return (this->value <= other.value);
}

bool	Fixed::operator==(const Fixed& other) const	{
	return (this->value == other.value);
}

bool	Fixed::operator!=(const Fixed& other) const	{
	return (this->value != other.value);
}

Fixed&	Fixed::operator++()	{
	this->value += 1;
	return (*this);
}

Fixed	Fixed::operator++(int)	{
	Fixed temp = *this;
	this->value += 1;
	return (temp);
}

Fixed&	Fixed::operator--()	{
	this->value -= 1;
	return (*this);
}

Fixed	Fixed::operator--(int)	{
	Fixed temp = *this;
	this->value -= 1;
	return (temp);
}

Fixed	Fixed::operator+(const Fixed& other) const	{
	Fixed result;
	result.value = (this->value + other.value);
	return (result);
}

Fixed	Fixed::operator-(const Fixed& other) const	{
	Fixed result;
	result.value = (this->value - other.value);
	return (result);
}

Fixed	Fixed::operator*(const Fixed& other) const	{
	Fixed result;
	result.value = (this->value * other.value) >> bit;
	return (result);
}

Fixed	Fixed::operator/(const Fixed& other) const	{
	Fixed result;
	result.value = (this->value << bit) / other.value;
	return (result);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)	{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)	{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)	{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)	{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}