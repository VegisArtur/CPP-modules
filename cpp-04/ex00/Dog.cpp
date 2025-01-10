#include "Dog.hpp"

Dog::Dog()	{
	std::cout << "Standard dog constructed." << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog& other)	{
	std::cout << "Standard dog copied." << std::endl;
	type = other.type;
}

Dog::~Dog()	{
	std::cout << "Standard dog deconstructed." << std::endl;
}

Dog& Dog::operator=(const Dog& other)	{
	if (this != &other)
		this->type = other.type;
	return *this;
}

void Dog::makeSound() const	{
	std::cout << "Bark" << std::endl;
}