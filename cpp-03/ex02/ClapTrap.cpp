#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string value) : name(value), hitPoints(100), energyPoints(50), attackDamage(20) {
	std::cout << name << "'s constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage) {
	std::cout << other.name << "'s copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap()	{
	std::cout << name << "'s destructor called" << std::endl;
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

std::string ClapTrap::getName()	{
	return name;
}

unsigned int ClapTrap::getHitpoints()	{
	return hitPoints;
}

unsigned int ClapTrap::getEnergyPoints()	{
	return energyPoints;
}

unsigned int ClapTrap::getAttackDamage()	{
	return attackDamage;
}

void ClapTrap::setName(std::string value)	{
	name = value;
}

void ClapTrap::setHitpoints(unsigned int value)	{
	hitPoints = value;
}

void ClapTrap::setEnergyPoints(unsigned int value)	{
	energyPoints = value;
}

void ClapTrap::setAttackDamage(unsigned int value)	{
	attackDamage = value;
}