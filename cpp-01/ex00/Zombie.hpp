#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>

class Zombie
{
	public:
		void announce(void)
		{
			if (name == "Foo")
			{
				std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
				return ;
			}
			std::cout << '<' << name << '>' << ": BraiiiiiiinnnzzzZ..." << std::endl;
		}
		Zombie(std::string str)
		{
			name = str;
		}
		void deadZombie(Zombie *zombie)
		{
			std::cout << name << ": has been killed!!" << std::endl;
			delete zombie;
		}

	private:
		std::string name;
};

void	randomChump(std::string name);
Zombie	*newZombie(std::string name);
void 	zombies(void);

#endif