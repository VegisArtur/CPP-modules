#include "Cat.hpp"

Cat::Cat()	{
	std::cout << "Standard cat constructed" << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat& other)	{
	std::cout << "Standard cat copied" << std::endl;
	type = other.type;
}

Cat::~Cat()	{
	std::cout << "Standard cat deconstructed" << std::endl;
}

Cat& Cat::operator=(const Cat& other)	{
	if (this != &other)
		this->type = other.type;
	return *this;
}