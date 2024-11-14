#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string value) : name(value) {
	std::cout << "Default constructor called" << std::endl;
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
}

ClapTrap::~ClapTrap()	{
	std::cout << "Default destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)	{
	std::cout << name << " hits " << target << " for " << attackDamage << "!!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)	{
	if (hitPoints < amount)
		hitPoints = 0;
	else
		hitPoints -= amount;
	std::cout << name << " takes " << amount << " damage, " << hitPoints << " health left." << std::endl;
	if (hitPoints == 0)
		std::cout << name << " is destroyed!!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)	{
	std::cout << name << " repairs themselves for " << amount << " points." << std::endl;
	hitPoints += amount;
}