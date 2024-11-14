#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap chad("Chad");

	chad.attack("Beta Cuck");
	chad.takeDamage(0);
	chad.beRepaired(1337);

	ScavTrap guard("Guardian");
	guard.attack("Attacker");
	guard.beRepaired(420);
	guard.takeDamage(3);
	guard.guardGate();
}