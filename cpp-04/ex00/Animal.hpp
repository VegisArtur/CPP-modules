#pragma once
#include <iostream>

class Animal
{
	public:
		Animal();
		Animal(const Animal& other);
		virtual ~Animal();

	protected:
		std::string type;

};