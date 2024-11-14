#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string value) : ClapTrap(value) {
	std::cout << value << "'s scav constructor called" << std::endl;
}

ScavTrap::~ScavTrap()	{
	std::cout << getName() << "'s scav destructor called" << std::endl;
}

void ScavTrap::guardGate()	{
	std::cout << getName() << " is now guarding the gate!!" << std::endl;
}