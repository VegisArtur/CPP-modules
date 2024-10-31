#include "Zombie.hpp"

Zombie::Zombie() : name("Unnamed")
{
}

Zombie::Zombie(std::string str) : name(str)
{
}

Zombie::~Zombie()
{
	std::cout << name << ": has been killed!!" << std::endl;
}

void	Zombie::assignName(std::string str)
{
	name = str;
}

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}