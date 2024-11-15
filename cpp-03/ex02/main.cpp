#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int	main(void)
{
	ClapTrap chad("Chad");
	ClapTrap gai(chad);

	gai.setName("Gai");
	gai.attack("Beta Cuck");
	chad.attack("Beta Cuck");
	chad.takeDamage(0);
	chad.beRepaired(1337);

	ScavTrap guard("Guardian");
	guard.attack("Attacker");
	guard.beRepaired(420);
	guard.takeDamage(3);
	guard.guardGate();
	
	ScavTrap aloof(guard);
	aloof.setName("Slacker");
	aloof.takeDamage(20);

	FragTrap hypeman("Hyper");
	std::cout << hypeman.getHitpoints() << std::endl;
	hypeman.beRepaired(69);
	std::cout << hypeman.getHitpoints() << std::endl;
	hypeman.highFivesGuys();
}