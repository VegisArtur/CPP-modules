#include "Zombie.hpp"

Zombie::Zombie() : name("Unnamed")
{
}

Zombie::Zombie(std::string str) : name(str)
{
}

void	Zombie::assignName(std::string str)
{
	name = str;
}

void Zombie::deadZombie(Zombie *zombie)
{
	std::cout << name << ": has been killed!!" << std::endl;
	delete zombie;
}

void Zombie::announce(void)
{
	if (name == "Foo")
	{
		std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
		return ;
	}
	std::cout << '<' << name << '>' << ": BraiiiiiiinnnzzzZ..." << std::endl;
}