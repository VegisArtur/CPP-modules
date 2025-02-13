#pragma once
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		~RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		void executeForm() const;
	
	private:
};