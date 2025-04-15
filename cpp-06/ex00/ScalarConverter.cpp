#include "ScalarConverter.hpp"
#include <iomanip>
#include <cstdlib>
#include <limits>
#include <cmath>

static void HandleNan(const std::string &literal)
{
	char charValue = '\0';
	int intValue = 0;
	float floatValue = 0.0f;
	double doubleValue = 0.0;

	if (literal == "nan")
	{
		doubleValue = std::stod(literal);
		intValue = static_cast<int>(doubleValue);
		charValue = static_cast<char>(intValue);
		floatValue = static_cast<float>(doubleValue);
	}
	else
	{
		floatValue = std::stof(literal);
		intValue = static_cast<int>(floatValue);
		charValue = static_cast<char>(intValue);
		doubleValue = static_cast<double>(floatValue);
	}
	std::cout << "char: " << "impossible" << std::endl;
	std::cout << "int: " << "impossible" << std::endl;
	std::cout << "float: " << std::fixed << floatValue << "f" << std::endl;
	std::cout << "double: " << std::fixed << doubleValue << std::endl;
}

void ScalarConverter::convert(const std::string &literal)
{
	if (literal == "nan" || literal == "nanf")
	{
		HandleNan(literal);
		return;
	}
	
	bool isChar = false, isInt = false, isFloat = false, isDouble = false;
	char charValue = '\0';
	int intValue = 0;
	float floatValue = 0.0f;
	double doubleValue = 0.0;

	if (literal.length() == 1 && !std::isdigit(literal[0]))
		isChar = true;
	else if (literal.find('.') == std::string::npos && literal.find('f') == std::string::npos)
		isInt = true;
	else if (literal.back() == 'f')
		isFloat = true;
	else
		isDouble = true;

	try
	{
		if (isChar)
		{
			charValue = literal[0];
			intValue = static_cast<int>(charValue);
			floatValue = static_cast<float>(charValue);
			doubleValue = static_cast<double>(charValue);
		}
		else if (isInt)
		{
			intValue = std::stoi(literal);
			charValue = static_cast<char>(intValue);
			floatValue = static_cast<float>(intValue);
			doubleValue = static_cast<double>(intValue);
		}
		else if (isFloat)
		{
			floatValue = std::stof(literal);
			intValue = static_cast<int>(floatValue);
			charValue = static_cast<char>(intValue);
			doubleValue = static_cast<double>(floatValue);
		}
		else if (isDouble)
		{
			doubleValue = std::stod(literal);
			intValue = static_cast<int>(doubleValue);
			charValue = static_cast<char>(intValue);
			floatValue = static_cast<float>(doubleValue);
		}
	}
	catch (...)
	{
		std::cout << "Error: Invalid input format" << std::endl;
		return;
	}

	std::cout << "char: ";
	if (isChar || (intValue >= std::numeric_limits<char>::min() && intValue <= std::numeric_limits<char>::max()))
	{
		if (std::isprint(charValue))
			std::cout << "'" << charValue << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;

	std::cout << "int: ";
	if (isChar || (doubleValue >= std::numeric_limits<int>::min() && doubleValue <= std::numeric_limits<int>::max()))
		std::cout << intValue << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << floatValue << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << doubleValue << std::endl;
}