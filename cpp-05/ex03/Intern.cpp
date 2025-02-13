#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) {(void)other;}

Intern::~Intern() {}

Intern& Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

typedef AForm* (*Forms)(std::string const&);
template<typename F>

AForm* forming(std::string const &target) {return new F(target);}

AForm* Intern::makeForm(std::string const &form, std::string const &target)
{
	std::string forms[3] = {"shrubbery request", "robotomy request", "pardon request"};
	Forms functions[3] = {forming<ShrubberyCreationForm>, forming<RobotomyRequestForm>, forming<PresidentialPardonForm>};

	for (int i = 0; i < 3; i++)
		if (forms[i] == form)
			return (functions[i](target));
	std::cout << "Invalid form" << std::endl;
	return nullptr;
}