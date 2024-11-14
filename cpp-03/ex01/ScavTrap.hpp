#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(std::string value);
		~ScavTrap();
		void guardGate();

	private:
};