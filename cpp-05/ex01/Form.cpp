#include "Form.hpp"

Form::Form(std::string name, int sign, int execute) : name(name), sign(0), toSign(sign), toExecute(execute)
{
	if (toSign < 1 || toExecute < 1)
		throw GradeTooHighException();
	if (toSign > 150 || toExecute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other) : name(other.name), sign(other.sign), toSign(other.toSign), toExecute(other.toExecute)
{
}

Form::~Form()
{
}

Form& Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->sign = other.sign;
	}
	return *this;
}

std::string Form::getName() const
{
	return name;
}

bool Form::getSignature() const
{
	return sign;
}

int Form::getSignGrade() const
{
	return toSign;
}

int Form::getExecutionGrade() const
{
	return toExecute;
}

std::ostream&	operator<<(std::ostream& os, const Form& ref) {

	if (ref.getSignature() == true)
		os << ref.getName() << " is signed." << std::endl;
	else
		os << ref.getName() << " is not signed." << std::endl;
	os << "To sign required grade = " << ref.getSignGrade() << std::endl;
	os << "To execute required grade = " << ref.getExecutionGrade() << std::endl;
	return (os);
}

const char* Form::GradeTooHighException::what() const noexcept {
	return ("Grade too high!!");
}

const char* Form::GradeTooLowException::what() const noexcept {
	return ("Grade too low!!");
}

void Form::beSigned(const Bureaucrat &worker)
{
	if (toSign < worker.getGrade())
		throw GradeTooLowException();
	sign = true;
}