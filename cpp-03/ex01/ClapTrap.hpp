#pragma once
#include <iostream>

class ClapTrap
{
	public:
		ClapTrap(std::string value);
		~ClapTrap();
		void 			attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void 			beRepaired(unsigned int amount);
		std::string		getName();
		unsigned int	getHitpoints();
		unsigned int	getEnergyPoints();
		unsigned int	getAttackDamage();

	private:
		std::string 	name;
		unsigned int	hitPoints;
		unsigned int	energyPoints;
		unsigned int	attackDamage;
};