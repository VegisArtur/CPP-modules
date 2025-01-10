#include "Cat.hpp"

Cat::Cat()	{
	std::cout << "Standard cat constructed" << std::endl;
	type = "Cat";
	brain = new Brain;
}

Cat::Cat(const Cat& other)	{
	std::cout << "Standard cat copied" << std::endl;
	type = other.type;
	brain = new Brain(*other.brain);
}

Cat::~Cat()	{
	std::cout << "Standard cat deconstructed" << std::endl;
	delete brain;
}

Cat& Cat::operator=(const Cat& other)	{
	if (this != &other)	{
		this->type = other.type;
		if (brain)
			delete brain;
		brain = new Brain(*other.brain);
	}
	return *this;
}

void Cat::makeSound() const	{
	std::cout << "Meow" << std::endl;
}

Brain*	Cat::getBrain() const	{
	return brain;
}