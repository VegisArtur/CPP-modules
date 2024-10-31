#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

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

	private:
		int value;
		static const int bit = 8;
};

std::ostream operator<<(std::ostream& os, Fixed& fixed);

#endif