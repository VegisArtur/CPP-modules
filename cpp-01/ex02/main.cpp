#include <iostream>

int	main(void)
{
	std::string original = "HI THIS IS BRAIN";
	std::string *stringPTR = &original;
	std::string &stringREF = original;
	std::cout << "Memory address of the string variable: " << &original << std::endl;
	std::cout << "Memory address held by the pointer:    " << stringPTR << std::endl;
	std::cout << "Memory address held by the reference:  " << &stringREF << std::endl;
	std::cout << "Value of the original:                 " << original << std::endl;
	std::cout << "Value of the pointer:                  " << *stringPTR << std::endl;
	std::cout << "Value of the reference:                " << stringREF << std::endl;
	return (0);
}