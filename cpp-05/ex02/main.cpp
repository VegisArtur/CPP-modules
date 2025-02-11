#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat bob(10, "Bob");
	Bureaucrat dan(140, "Dan");
	ShrubberyCreationForm woods("Woods");

	std::cout << woods;

	bob.executeForm(woods);
	dan.signForm(woods);
	dan.executeForm(woods);
	bob.executeForm(woods);

	std::cout << "---------- ||| ----------" << std::endl;

	return 0;
}