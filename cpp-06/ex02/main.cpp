#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
	int		quantity = 10;
    Base    gen;
    Base*   p;

	std::srand(std::time(nullptr));
    for (int i = 0; i < quantity; i++)
    {
        p = gen.generate();
		if (p == nullptr)
		{
			std::cout << "Error creating object!!" << std::endl;
			return 1;
		}
        gen.identify(p);
        gen.identify(*p);
		if (i < quantity - 1)
			std::cout << std::endl;
        delete p;
    }
    return 0;
}