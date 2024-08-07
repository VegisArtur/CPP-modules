#include "Zombie.hpp"
#include <string>

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie* zombies = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		zombies[i].assignName(name);
	}
	return (zombies);
}

void	deletHorde(Zombie *zombies)
{
	delete zombies;
}