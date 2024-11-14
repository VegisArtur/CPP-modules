#include "Weapon.hpp"

Weapon::Weapon() : type("typeless weapon") {
}

Weapon::Weapon(std::string str) : type(str) {
}

const std::string&	Weapon::getType() {
	return (type);
}

void	Weapon::setType(std::string str) {
	type = str;
}