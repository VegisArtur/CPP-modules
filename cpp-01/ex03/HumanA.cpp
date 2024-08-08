#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string str, Weapon &weapon) : name(str), weaponType(weapon) {
}

void	HumanA::attack() {
	std::cout << name << " attacks with their " << weaponType.getType() << std::endl;
}