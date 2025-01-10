#include "Dog.hpp"

Dog::Dog()	{
	std::cout << "Standard dog constructed." << std::endl;
	type = "Dog";
	brain = new Brain;
}

Dog::Dog(const Dog& other)	{
	std::cout << "Standard dog copied." << std::endl;
	type = other.type;
	brain = new Brain(*other.brain);
}

Dog::~Dog()	{
	std::cout << "Standard dog deconstructed." << std::endl;
	delete brain;
}

Dog& Dog::operator=(const Dog& other)	{
	if (this != &other)	{
		this->type = other.type;
		if (brain)
			delete brain;
		brain = new Brain(*other.brain);
	}
	return *this;
}

void Dog::makeSound() const	{
	std::cout << "Bark" << std::endl;
}

Brain*	Dog::getBrain() const	{
	return brain;
}