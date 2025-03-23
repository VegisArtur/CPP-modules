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
    Base    gen;
    Base*   p;

	std::srand(std::time(nullptr));
    for (int i = 0; i < 10; i++)
    {
        p = gen.generate();
        gen.identify(p);
        gen.identify(*p);
        delete p;
    }
    return 0;
}