#include "ScalarConverter.hpp"
#include <iomanip>
#include <cstdlib>
#include <limits>
#include <cmath>

void ScalarConverter::convert(const std::string &literal)
{
	char charValue;
	int intValue;
	float floatValue;
	double doubleValue;

	// Convert to int if possible
	try {intValue = std::stoi(literal);} catch (...) {intValue = 0;}

	// Convert to float and double
	try {
		floatValue = std::stof(literal);
		doubleValue = std::stod(literal);
	} catch (...) {
		floatValue = 0.0f;
		doubleValue = 0.0;
	}

	// Convert to char if it's a single character or valid ASCII
	if (literal.length() == 1 && !std::isdigit(literal[0])) {
		charValue = literal[0];
	} else if (intValue >= std::numeric_limits<char>::min() && intValue <= std::numeric_limits<char>::max()) {
		charValue = static_cast<char>(intValue);
	} else {
		charValue = '\0'; // Invalid char representation
	}

	// Print the results
	std::cout << "char: ";
	if (std::isprint(charValue)) {
		std::cout << "'" << charValue << "'" << std::endl;
	} else {
		std::cout << "Non displayable" << std::endl;
	}

	std::cout << "int: " << intValue << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << floatValue << "f" << std::endl;
	std::cout << "double: " << doubleValue << std::endl;
}

// #include <iostream>
// #include <string>
// #include <limits>
// #include <sstream>
// #include <cctype>
// #include <cmath>

// enum type
// {
//     NONE,
//     CHAR,
//     INT,
//     FLOAT,
//     DOUBLE
// };

// static type analyze(std::string const& str)
// {
//     int    len = str.length();
//     if (len == 0)
//         return (NONE);
//     if (str[0] == '\'' && len == 3)
//     {
//         if (!std::isprint(str[1]) || str[1] == ' ' || str[2] != '\'')
//             return (NONE);
//         return (CHAR);
//     }
//     if (str == "-inff" || str == "+inff" || str == "nanf")
//         return (FLOAT);
//     if (str == "-inf" || str == "+inf" || str == "nan")
//         return (DOUBLE);
//     if (!std::isdigit(str[0]))
//         if (str[0] != '+' && str[0] != '-')
//             return (NONE);
//     for (int i = 1; i < len; i++)
//     {
//         if (str[i] == '.' && i != len - 1)
//         {
//             for (int j = i + 1; j < len; j++)
//             {
//                 if (j == len - 1 && str[j] == 'f' && str[j - 1] != '.')
//                     return (FLOAT);
//                 if (!std::isdigit(str[j]))
//                     return (NONE);
//             }
//             return (DOUBLE);
//         }
//         if (!std::isdigit(str[i]))
//             return (NONE);
//     }
//     return (INT);
// }

// static void    convertChar(char c)
// {
//     std::cout << "char: '" << c << "'\n";
//     std::cout << "int: " << static_cast<int>(c) << "\n";
//     std::cout << "float: " << static_cast<float>(c) << "\n";
//     std::cout << "double: " << static_cast<double>(c) << "\n";
// }

// static void    convertInt(std::stringstream &ss)
// {
//     int nb;
    
//     if (!(ss >> nb))
//     {
//         std::cout << "invalid input\n";
//         return;
//     }
//     if (std::numeric_limits<char>::min() <= nb && nb <= std::numeric_limits<char>::max())
//     {
//         char c = static_cast<char>(nb);
//         if (std::isprint(c) && c != ' ')
//             std::cout << "char: '" << c << "'\n";
//         else
//             std::cout << "char: Non displayable\n";
//     }
//     else
//         std::cout << "char: impossible\n";
//     std::cout << "int: " << nb << "\n";
//     std::cout << "float: " << static_cast<float>(nb) << "\n";
//     std::cout << "double: " << static_cast<double>(nb) << "\n";
// }

// static void    convertFloat(std::stringstream &ss)
// {
//     float   nb;
    
//     if (!(ss >> nb))
//     {
//         std::cout << "invalid input\n";
//         return;
//     }
//     if (std::numeric_limits<char>::min() <= nb && nb <= std::numeric_limits<char>::max()
//         && !std::isinf(nb) && !std::isnan(nb))
//     {
//         char c = static_cast<char>(nb);
//         if (std::isprint(c) && c != ' ')
//             std::cout << "char: '" << c << "'\n";
//         else
//             std::cout << "char: Non displayable\n";
//     }
//     else
//         std::cout << "char: impossible\n";
//     if (std::numeric_limits<int>::min() <= nb && nb <= std::numeric_limits<int>::max()
//         && !std::isinf(nb) && !std::isnan(nb))
//     {
//         std::cout << "int: " << static_cast<int>(nb) << "\n";
//     }
//     else
//         std::cout << "int: impossible\n";
//     std::cout << "float: " << nb << "\n";
//     std::cout << "double: " << static_cast<double>(nb) << "\n";
// }

// static void    convertDouble(std::stringstream &ss)
// {
//     double  nb;
    
//     if (!(ss >> nb))
//     {
//         std::cout << "invalid input\n";
//         return;
//     }
//     if (std::numeric_limits<char>::min() <= nb && nb <= std::numeric_limits<char>::max()
//         && !std::isinf(nb) && !std::isnan(nb))
//     {
//         char c = static_cast<char>(nb);
//         if (std::isprint(c) && c != ' ')
//             std::cout << "char: '" << c << "'\n";
//         else
//             std::cout << "char: Non displayable\n";
//     }
//     else
//         std::cout << "char: impossible\n";
//     if (std::numeric_limits<int>::min() <= nb && nb <= std::numeric_limits<int>::max()
//         && !std::isinf(nb) && !std::isnan(nb))
//     {
//         std::cout << "int: " << static_cast<int>(nb) << "\n";
//     }
//     else
//         std::cout << "int: impossible\n";
//     if (-std::numeric_limits<float>::max() > nb || nb > std::numeric_limits<float>::max())
//         std::cout << "float: impossible\n";
//     else
//         std::cout << "float: " << static_cast<float>(nb) << "\n";
//     std::cout << "double: " << nb << "\n";
// }

// void ScalarConverter::convert(std::string str)
// {
//     type    t = analyze(str);
//     if (t == FLOAT)
//         str.erase(str.length() - 1, 1);
//     std::stringstream   ss(str);
//     switch (t)
//     {
//         case CHAR:
//             convertChar(str[1]);
//             break;
//         case INT:
//             convertInt(ss);
//             break;
//         case FLOAT:
//             convertFloat(ss);
//             break;
//         case DOUBLE:
//             convertDouble(ss);
//             break;
//         default:
//             std::cout << "invalid input\n";
//     }
// }