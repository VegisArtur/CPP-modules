#pragma once
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap(std::string value);
		FragTrap(const ClapTrap& other);
		~FragTrap();
		void	highFivesGuys(void);

	private:

};