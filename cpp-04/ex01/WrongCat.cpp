#include "WrongCat.hpp"

WrongCat::WrongCat()	{
	std::cout << "Wrong cat constructed" << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other)	{
	std::cout << "Wrong cat copied" << std::endl;
	type = other.type;
}

WrongCat::~WrongCat()	{
	std::cout << "Wrong cat deconstructed" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)	{
	if (this != &other)
		this->type = other.type;
	return *this;
}

void WrongCat::makeSound() const	{
	std::cout << "Mow" << std::endl;
}