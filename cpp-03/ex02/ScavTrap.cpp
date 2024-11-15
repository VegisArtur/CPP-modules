#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string value) : ClapTrap(value) {
	std::cout << value << "'s scav constructor called" << std::endl;
	setHitpoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
}

ScavTrap::ScavTrap(const ScavTrap& other)	: ClapTrap(other)	{
	std::cout << getName() << "'s scav copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()	{
	std::cout << getName() << "'s scav destructor called" << std::endl;
}

void ScavTrap::guardGate()	{
	std::cout << getName() << " is now guarding the gate!!" << std::endl;
}