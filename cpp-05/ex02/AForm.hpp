#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

std::ostream& operator<<(std::ostream& os, const class AForm& ref);

class AForm
{
	public:
		AForm(std::string name, int sign, int execute);
		AForm(const AForm &other);
		~AForm();
		AForm& operator=(const AForm &other);
		void beSigned(const Bureaucrat &worker);
		std::string getName() const;
		bool getSignature() const;
		int getSignGrade() const;
		int getExecutionGrade() const;
		void execute(Bureaucrat const &executor) const;

	private:
		const std::string name;
		bool sign;
		const int toSign;
		const int toExecute;
		virtual void executeForm() const = 0;
		class GradeTooHighException : public std::exception 
		{
			const char* what() const noexcept;
		};
		class GradeTooLowException : public std::exception 
		{
			const char* what() const noexcept;
		};

		class FormNotSignedException : public std::exception 
		{
			const char* what() const noexcept;
		};

};