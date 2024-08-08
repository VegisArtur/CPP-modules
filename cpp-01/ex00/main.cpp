#include "Zombie.hpp"

int	main(void)
{
	std::string input;
	std::cout << std::endl << "Testing newZombie function, enter name for zombie." << std::endl;
	std::getline(std::cin, input);
	Zombie *zombie = newZombie(input);
	zombie->announce();
	delete zombie;
	std::cout << std::endl << "Testing randomChump function, enter name for zombie." << std::endl;
	std::getline(std::cin, input);
	randomChump(input);
	return (0);
}