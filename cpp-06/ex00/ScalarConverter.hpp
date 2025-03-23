#pragma once
#include <iostream>
#include <string>

class ScalarConverter
{
	public:
		static void convert(const std::string &literal);
	
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const& ref);
		ScalarConverter& operator=(ScalarConverter const& ref);
		~ScalarConverter();
};