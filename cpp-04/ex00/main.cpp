#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)	{
	Animal ghost1;
	ghost1.makeSound();
	Animal ghost2(ghost1);

	Dog dog;
	dog.makeSound();

	std::cout << "---------------------" << std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;

	std::cout << "---------------------" << std::endl;

	const WrongAnimal* what = new WrongAnimal();
	const WrongAnimal* u = new WrongCat();
	std::cout << u->getType() << " " << std::endl;
	u->makeSound();
	what->makeSound();
	delete what;
	delete u;

	std::cout << "---------------------" << std::endl;
}