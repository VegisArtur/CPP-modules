#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5)
{	
}

void PresidentialPardonForm::executeForm() const
{
	std::cout << getName() << " was pardoned by Zaphod Beeblebrox" << std::endl;
}