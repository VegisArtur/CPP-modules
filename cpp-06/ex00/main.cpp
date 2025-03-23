#include "ScalarConverter.hpp"

int main() {
	ScalarConverter::convert("42.0f");      // Should print char, int, float, double
	std::cout << std::endl;
	ScalarConverter::convert("1");      // Should print char, int, float, double
	std::cout << std::endl;
	ScalarConverter::convert("a");       // Should recognize it as a char
	std::cout << std::endl;
	ScalarConverter::convert("3.14");    // Should convert to float and double
	std::cout << std::endl;
	ScalarConverter::convert("nan");     // Special floating-point case
	std::cout << std::endl;
	ScalarConverter::convert("inff");     // Infinity handling
	std::cout << std::endl;
	ScalarConverter::convert("-inf");   // Negative infinity
	std::cout << std::endl;

	// ScalarConverter asd;

	// asd.convert("asd");
	return 0;
}