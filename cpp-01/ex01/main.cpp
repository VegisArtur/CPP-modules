#include "Zombie.hpp"

int	main(void)
{
	int Decrepit = 5;
	int Fresh = 2;
	Zombie* hordeOne = zombieHorde(Decrepit, "Decrepit Zombie");
	Zombie* hordeTwo = zombieHorde(Fresh, "Fresh Zombie");
	for (int i = 0; i < Decrepit; i++)
		hordeOne[i].announce();
	for (int i = 0; i < Fresh; i++)
		hordeOne[i].announce();
	deletHorde(hordeOne);
	while (Fresh > 0)
	{
		hordeTwo->deadZombie(hordeTwo[Fresh]);

	}
	return (0);
}