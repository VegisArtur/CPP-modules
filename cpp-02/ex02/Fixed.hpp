#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed(const int raw);
		Fixed(const float raw);
		~Fixed();
		Fixed& operator=(const Fixed& C);
		int		getRawBits( void ) const;
		int		getBit( void ) const;
		void	setRawBits( int const raw);
		float	toFloat( void ) const;
		int		toInt( void ) const;
		Fixed	Fixed::operator>(const Fixed& other) const;
		Fixed&	Fixed::operator++();
		Fixed&	Fixed::operator++(int);
		Fixed&	Fixed::operator--();
		Fixed&	Fixed::operator--(int);
		Fixed	Fixed::operator+(const Fixed& other) const;
		Fixed	Fixed::operator-(const Fixed& other) const;
		Fixed	Fixed::operator*(const Fixed& other) const;
		Fixed	Fixed::operator/(const Fixed& other) const;
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);

	private:
		int value;
		static const int bit = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif