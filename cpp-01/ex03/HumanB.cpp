#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string str) : name(str) {
}

void	HumanB::setWeapon(Weapon &weapon) {
	weaponType = &(weapon.getType());
}

void	HumanB::attack() {
	std::cout << name << " attacks with their " << *weaponType << std::endl;
}