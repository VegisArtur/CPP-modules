#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Bureaucrat worker(150, "worker");
	Bureaucrat office(130, "office");
	Bureaucrat general(10, "general");
	Bureaucrat president(1, "halonen");
	Intern idiot;

	AForm *woods;
	woods = idiot.makeForm("shrubbery request", "woods");
	worker.signForm(*woods);
	president.executeForm(*woods);
	general.signForm(*woods);
	office.executeForm(*woods);
	delete woods;

	std::cout << "---------- ||| ----------" << std::endl;

	AForm *robot;
	robot = idiot.makeForm("robotomy request", "iRobot");
	std::cout << *robot << std::endl;
	delete robot;

	std::cout << "---------- ||| ----------" << std::endl;

	AForm *prez;
	prez = idiot.makeForm("bomb location", "nuke");
	prez = idiot.makeForm("pardon request", "burrows");
	std::cout << *prez << std::endl;
	delete prez;

	return 0;
}
