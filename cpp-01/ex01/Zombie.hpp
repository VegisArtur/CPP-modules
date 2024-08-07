#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>

class Zombie
{
	public:
		Zombie();
		Zombie(std::string str);
		void 	Zombie::announce(void);
		void	Zombie::deadZombie(Zombie *zombie);
		void	Zombie::assignName(std::string str);

	private:
		std::string name;
};

Zombie	*zombieHorde(int N, std::string name);
void	deletHorde(Zombie *zombies);

#endif