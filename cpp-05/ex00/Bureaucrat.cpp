#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(int grade, const std::string &name) : name(name), grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)	
{
	if (this != &other)
	{
		this->grade = other.grade;
	}
	return *this;
}

std::string Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

void Bureaucrat::incrementGrade()
{
	if (grade - 1 < 1)
		throw(GradeTooHighException());
	grade--;
}

void Bureaucrat::decrementGrade()
{
	if (grade + 1 > 150)
		throw(GradeTooLowException());
	grade++;
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& ref) {
	os << ref.getName() << ", grade = " << ref.getGrade() << std::endl;
	return (os);
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept {
	return ("Grade too high!!");
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept {
	return ("Grade too low!!");
}