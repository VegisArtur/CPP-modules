#include "Brain.hpp"

Brain::Brain()	{
	std::cout << "Brain constructed." << std::endl;
}

Brain::Brain(const Brain& other) {
	std::cout << "Brain copy constructed." << std::endl;
	for (int i = 0; i < 100; i++)	{
		ideas[i] = other.ideas[i];
	}
	c_idea = other.c_idea;
}

Brain::~Brain()	{
	std::cout << "Brain deconstructed." << std::endl;
}

Brain& Brain::operator=(const Brain& other)	{
	std::cout << "Brain copied" << std::endl;
	if (this != &other)	{
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
		c_idea = other.c_idea;
	}
	return *this;
}

void Brain::setIdea(std::string idea)	{
	if (c_idea == 100)	{
		c_idea = 0;
	}
	ideas[c_idea] = idea;
	c_idea++;
}

void Brain::printIdeas()	{
	for (int i = 0; i < 100; i++)
		if (!ideas[i].empty())
			std::cout << ideas[i] << std::endl;
}