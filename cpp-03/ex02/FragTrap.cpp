#include "FragTrap.hpp"

FragTrap::FragTrap(std::string value)	: ClapTrap(value)	{
	std::cout << value << "'s frag constructor called" << std::endl;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}

FragTrap::FragTrap(const ClapTrap& other)	:	ClapTrap(other)	{
	std::cout << name << "'s frag copy constructor called" << std::endl;
}

FragTrap::~FragTrap()	{
	std::cout << name << "'s frag destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)	{
	std::cout << name << " tries to highfive his fellow constructs!!" << std::endl;
}