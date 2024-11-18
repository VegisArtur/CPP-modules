#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()	{
	std::cout << "Wrong animal constructed." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)	: type(other.type)	{
	std::cout << "Wrong animal copied." << std::endl;
}

WrongAnimal::~WrongAnimal()	{
	std::cout << "Wrong animal deconstructed." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)	{
	if (this != &other)
		this->type = other.type;
	return *this;
}

void WrongAnimal::makeSound() const	{
	if (type == "Cat")
		std::cout << "Mow" << std::endl;
	else
		std::cout << "Buuu" << std::endl;
}

std::string WrongAnimal::getType() const	{
	return type;
}