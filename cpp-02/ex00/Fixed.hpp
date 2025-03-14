#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed& other);
		~Fixed();
		Fixed& operator=(const Fixed& C);
		int getRawBits(void) const;
		void setRawBits(int const raw);

	private:
		int value;
		static const int bit = 8;
};

#endif