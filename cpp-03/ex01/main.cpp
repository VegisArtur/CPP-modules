#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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
}