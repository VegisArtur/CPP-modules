#pragma once
#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &other);
		~Intern();
		Intern& operator=(const Intern &other);
		AForm* makeForm(std::string const &form, std::string const &target);
};