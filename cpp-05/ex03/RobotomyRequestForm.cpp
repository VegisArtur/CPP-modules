#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45)
{	
}

void    RobotomyRequestForm::executeForm() const
{
    std::srand(std::time(NULL));
    if (std::rand() & 0x1)
        std::cout << getName() << " has been robotomized succesfully\n";
    else
        std::cout << "Robotomy failed\n";
}