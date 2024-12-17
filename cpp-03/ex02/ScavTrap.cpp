#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string value) : ClapTrap(value) {
	std::cout << value << "'s scav constructor called" << std::endl;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other)	: ClapTrap(other)	{
	std::cout << name << "'s scav copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()	{
	std::cout << name << "'s scav destructor called" << std::endl;
}

void ScavTrap::guardGate()	{
	std::cout << name << " is now guarding the gate!!" << std::endl;
}

void ScavTrap::attack(const std::string& target)	{
	if (energyPoints == 0)	{
		std::cout << name << " doesnt have enough energy to attack!!" << std::endl;
		return ;
	}
	std::cout << name << " hits " << target << " for " << attackDamage << "!! Woah!!" << std::endl;
	energyPoints--;
}