#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(std::string value);
		ScavTrap(const ScavTrap& other);
		~ScavTrap();
		void attack(const std::string& target);
		void guardGate();

	private:
};