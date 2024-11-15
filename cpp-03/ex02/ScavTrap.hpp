#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(std::string value);
		ScavTrap(const ScavTrap& other);
		~ScavTrap();
		void guardGate();

	private:
};