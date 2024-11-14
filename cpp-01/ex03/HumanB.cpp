#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string str) : name(str) {
	weapon = NULL;
}

void	HumanB::setWeapon(Weapon &externalWeapon) {
	weapon = &externalWeapon;
}

void	HumanB::attack() {
	if (!weapon)
		std::cout << name << " attacks with their fist" << std::endl;
	else
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}