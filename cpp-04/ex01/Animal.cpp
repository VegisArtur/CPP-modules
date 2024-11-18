#include "Animal.hpp"

Animal::Animal()	{
	std::cout << "Standard animal constructed." << std::endl;
}

Animal::Animal(const Animal& other)	: type(other.type)	{
	std::cout << "Standard animal copied." << std::endl;
}

Animal::~Animal()	{
	std::cout << "Standard animal deconstructed." << std::endl;
}

Animal& Animal::operator=(const Animal& other)	{
	if (this != &other)
		this->type = other.type;
	return *this;
}

void Animal::makeSound() const	{
	if (type == "Cat")	{
		std::cout << "Meow" << std::endl;
		return ;
	}
	else if (type == "Dog")	{
		std::cout << "Bark" << std::endl;
		return ;
	}
	else
		std::cout << "BOOOooOOooOOO" << std::endl;
}

std::string Animal::getType() const	{
	return type;
}