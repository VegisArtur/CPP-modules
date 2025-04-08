#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat bob(135, "Bob");
	Bureaucrat dan(140, "Dan");
	ShrubberyCreationForm woods("Woods");

	std::cout << woods;

	std::cout << "---------- ||| ----------" << std::endl;

	bob.executeForm(woods);
	dan.signForm(woods);
	dan.executeForm(woods);
	bob.executeForm(woods);

	std::cout << "---------- ||| ----------" << std::endl;

	Bureaucrat scientist(24, "scientist");
	RobotomyRequestForm duh("duh");

	std::cout << duh;

	scientist.executeForm(duh);
	scientist.signForm(duh);
	scientist.executeForm(duh);

	std::cout << "---------- ||| ----------" << std::endl;

	Bureaucrat president(4, "Beeble");
	PresidentialPardonForm scofield("scofield");

	scientist.signForm(scofield);
	scientist.executeForm(scofield);
	president.executeForm(scofield);

	return 0;
}