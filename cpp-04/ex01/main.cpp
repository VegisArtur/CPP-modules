#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)	{
	Animal zoo[10];
	for (int i = 0; i < 10; i++)	{
		if (i % 2 == 0)	{
			zoo[i] = new Dog;
			continue ;
		}
		zoo[i] = new Cat;
	}
	std::cout << "---------------------" << std::endl;
}