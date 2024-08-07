#include "Zombie.hpp"

void	zombies(void)
{
	std::string input;
	std::cout << std::endl << "Testing newZombie function" << std::endl;
	std::getline(std::cin, input);
	Zombie *zombie = newZombie(input);
	zombie->announce();
	zombie->deadZombie(zombie);
	std::cout << std::endl << "Testing randomChump function" << std::endl;
	std::getline(std::cin, input);
	randomChump(input);
}