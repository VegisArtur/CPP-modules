#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << a.toFloat() << std::endl;
	Fixed const c(a + Fixed(12));
	std::cout << c << std::endl;
	if (c > b)
		std::cout << "c is larger than b" << std::endl;
	else if (c < b)
		std::cout << "b is larger than c" << std::endl;
	if (c == c)
		std::cout << "they are equal" << std::endl;
	Fixed const d(Fixed(2) / Fixed(1));
	std::cout << d.toInt() << std::endl;
	return 0;
}