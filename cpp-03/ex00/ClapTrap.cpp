#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string value) : name(value) {
	std::cout << "Default constructor called" << std::endl;
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage) {
	std::cout << other.name << "'s copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap()	{
	std::cout << "Default destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)	{
	if (energyPoints == 0)	{
		std::cout << name << " doesnt have enough energy to attack!!" << std::endl;
		return ;
	}
	std::cout << name << " hits " << target << " for " << attackDamage << "!!" << std::endl;
	energyPoints--;
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
	if (energyPoints == 0)	{
		std::cout << name << " doesnt have enough energy to repair!!" << std::endl;
		return ;
	}
	std::cout << name << " repairs themselves for " << amount << " points." << std::endl;
	hitPoints += amount;
	energyPoints--;
}