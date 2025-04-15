#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base* Base::generate()
{
	int random = std::rand() % 3;

	if (random == 0)
		return new A();
	else if (random == 1)
		return new B();
	else if (random == 2)
		return new C();
	return nullptr;
}

void Base::identify(Base* p)
{
	std::cout << "Pointer = ";
	if (dynamic_cast<A*>(p))
		std::cout << "Type A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Type B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Type C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void Base::identify(Base& p)
{
	std::cout << "Reference = ";
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Type A" << std::endl;
		return;
	}
	catch (...) {}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Type B" << std::endl;
		return;
	}
	catch (...) {}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Type C" << std::endl;
		return;
	}
	catch (...) {}

	std::cout << "Unknown type" << std::endl;
}