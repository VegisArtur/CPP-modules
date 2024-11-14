#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP
#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string str, Weapon &type);
		void	attack();

	private:
		std::string	name;
		Weapon& weapon;
};

#endif