#include "Zombie.hpp"

int	main(void)
{
	Zombie zombiea;
	zombiea.assignName("sad");
	int Decrepit = 5;
	int Fresh = 2;
	Zombie* hordeOne = zombieHorde(Decrepit, "Decrepit Zombie");
	Zombie* hordeTwo = zombieHorde(Fresh, "Fresh Zombie");
	for (int i = 0; i < Decrepit; i++)
		hordeOne[i].announce();
	for (int i = 0; i < Fresh; i++)
		hordeTwo[i].announce();
	delete[] hordeOne;
	delete[] hordeTwo;
	return (0);
}