#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

std::ostream& operator<<(std::ostream& os, const class Form& ref);

class Form
{
	public:
		Form(std::string name, int sign, int execute);
		Form(const Form &other);
		~Form();
		Form& operator=(const Form &other);
		void beSigned(const Bureaucrat &worker);
		std::string getName() const;
		bool getSignature() const;
		int getSignGrade() const;
		int getExecutionGrade() const;

	private:
		const std::string name;
		bool sign;
		const int toSign;
		const int toExecute;
		class GradeTooHighException : public std::exception 
		{
			const char* what() const noexcept;
		};

		class GradeTooLowException : public std::exception 
		{
			const char* what() const noexcept;
		};
};