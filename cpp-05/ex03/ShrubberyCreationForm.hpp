#pragma once
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		~ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		void executeForm() const;
	
	private:
};