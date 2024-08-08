#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string str);
		void	setWeapon(Weapon &weapon);
		void	attack();

	private:
		std::string	name;
		const std::string *weaponType;
};

#endif