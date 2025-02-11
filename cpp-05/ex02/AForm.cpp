#include "AForm.hpp"

AForm::AForm(std::string name, int sign, int execute) : name(name), sign(0), toSign(sign), toExecute(execute)
{
	if (toSign < 1 || toExecute < 1)
		throw GradeTooHighException();
	if (toSign > 150 || toExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other) : name(other.name), sign(other.sign), toSign(other.toSign), toExecute(other.toExecute)
{
}

AForm::~AForm()
{
}

AForm& AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		this->sign = other.sign;
	}
	return *this;
}

std::string AForm::getName() const
{
	return name;
}

bool AForm::getSignature() const
{
	return sign;
}

int AForm::getSignGrade() const
{
	return toSign;
}

int AForm::getExecutionGrade() const
{
	return toExecute;
}

std::ostream&	operator<<(std::ostream& os, const AForm& ref) {

	if (ref.getSignature() == true)
		os << ref.getName() << " is signed." << std::endl;
	else
		os << ref.getName() << " is not signed." << std::endl;
	os << "To sign required grade = " << ref.getSignGrade() << std::endl;
	os << "To execute required grade = " << ref.getExecutionGrade() << std::endl;
	return (os);
}

const char* AForm::GradeTooHighException::what() const noexcept {
	return ("Grade too high!!");
}

const char* AForm::GradeTooLowException::what() const noexcept {
	return ("Grade too low!!");
}

const char* AForm::FormNotSignedException::what() const noexcept {
	return ("Form not signed!!");
}

void AForm::beSigned(const Bureaucrat &worker)
{
	if (toSign < worker.getGrade())
		throw GradeTooLowException();
	sign = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (getSignature() == false)
	{
		throw FormNotSignedException();
	}
	if (getExecutionGrade() < executor.getGrade())
	{
		throw GradeTooLowException();
	}
	executeForm();
}