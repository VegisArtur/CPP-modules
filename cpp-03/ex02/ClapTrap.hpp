#pragma once
#include <iostream>

class ClapTrap
{
	public:
		ClapTrap(std::string value);
		ClapTrap(const ClapTrap& other);
		~ClapTrap();
		void 			attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void 			beRepaired(unsigned int amount);
		std::string		getName();
		unsigned int	getHitpoints();
		unsigned int	getEnergyPoints();
		unsigned int	getAttackDamage();
		void			setName(std::string value);
		void			setHitpoints(unsigned int value);
		void			setEnergyPoints(unsigned int value);
		void			setAttackDamage(unsigned int value);


	private:
		std::string 	name;
		unsigned int	hitPoints;
		unsigned int	energyPoints;
		unsigned int	attackDamage;
};