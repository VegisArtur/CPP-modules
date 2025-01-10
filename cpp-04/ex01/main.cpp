#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)	{
	const Animal *zoo[10];
	int count = 10;

	for (int i = 0; i < count; i++)	{
		if (i % 2 == 0)	{
			zoo[i] = new Dog;
			continue ;
		}
		zoo[i] = new Cat;
	}
	std::cout << "---------------------" << std::endl;

	dynamic_cast<const Dog*>(zoo[0])->getBrain()->setIdea("Chew toy");
	dynamic_cast<const Dog*>(zoo[0])->getBrain()->setIdea("Run around");
	dynamic_cast<const Dog*>(zoo[0])->getBrain()->printIdeas();

	std::cout << std::endl;

	const Dog doppel = *dynamic_cast<const Dog *>(zoo[0]);
	dynamic_cast<const Dog*>(zoo[0])->getBrain()->setIdea("Brain Rot");

	std::cout << std::endl;

	doppel.getBrain()->printIdeas();

	std::cout << std::endl;

	dynamic_cast<const Dog*>(zoo[0])->getBrain()->printIdeas();

	std::cout << "---------------------" << std::endl;

	for (int i = 0; i < count; i++)	{
		delete zoo[i];
	}

	std::cout << std::endl;

	return 0;
}