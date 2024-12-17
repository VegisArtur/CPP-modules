#pragma once
#include <iostream>

class Brain
{
	public:
		Brain();
		Brain(const Brain& other);
		~Brain();
		Brain&	operator=(const Brain& other);
		void	setIdea(std::string idea);
		void	printIdeas();

	private:
		std::string ideas[100];
		int			c_idea;
};