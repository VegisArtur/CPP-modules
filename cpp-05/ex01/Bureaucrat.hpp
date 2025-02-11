#pragma once
#include <iostream>

std::ostream& operator<<(std::ostream& os, const class Bureaucrat& ref);

class Form;

class Bureaucrat
{
	public:
		Bureaucrat(int grade, const std::string &name);
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat &other);
		std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		void signForm(Form &ref);
		
	private:
		const std::string	name;
		int 				grade;
		class GradeTooHighException : public std::exception 
		{
			const char* what() const noexcept;
		};

		class GradeTooLowException : public std::exception 
		{
			const char* what() const noexcept;
		};
};

