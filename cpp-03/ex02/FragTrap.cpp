#include "FragTrap.hpp"

FragTrap::FragTrap(std::string value)	: ClapTrap(value)	{
	std::cout << value << "'s frag constructor called" << std::endl;
	setHitpoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
}

FragTrap::FragTrap(const ClapTrap& other)	:	ClapTrap(other)	{
	std::cout << getName() << "'s frag copy constructor called" << std::endl;
}

FragTrap::~FragTrap()	{
	std::cout << getName() << "'s frag destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)	{
	std::cout << getName() << " tries to highfive his fellow constructs!!" << std::endl;
}