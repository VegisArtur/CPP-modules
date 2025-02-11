#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat	b1(150, "Normie");
	Bureaucrat	b2(1, "Lormie");
	std::cout << b1;
	std::cout << b2.getName() << " " << b2.getGrade() << std::endl;

	try {
		b1.incrementGrade();
		std::cout << b1;
		b2.decrementGrade();
		std::cout << b2;
	}
	catch (std::exception &e) 
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "---------- ||| ----------" << std::endl;

	b1.decrementGrade();

	try {
		b1.decrementGrade();
	}
	catch (std::exception &e) 
	{
		std::cout << e.what() << std::endl;
	}

	b2.incrementGrade();

	try {
		b2.incrementGrade();
	}
	catch (std::exception &e) 
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "---------- ||| ----------" << std::endl;

	try 
	{
		Bureaucrat	b3(0, "Dormie");
	}
	catch (std::exception &e) 
	{
		std::cout << e.what() << std::endl;
	}

	try 
	{
		Bureaucrat	b4(151, "Hormie");
	}
	catch (std::exception &e) 
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}