#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Invalid argument count!!!" << std::endl;
		return 1;
	}

	RPN calculator;

	calculator.calculate(argv[1]);

	return 0;
}