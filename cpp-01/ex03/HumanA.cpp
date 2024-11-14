#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string str, Weapon &weapon) : name(str), weapon(weapon) {
}

void	HumanA::attack() {
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}