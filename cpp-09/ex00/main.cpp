#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "Use the input file argument silly!" << std::endl;
		return 1;
	}

	try
	{
		BitcoinExchange btc;
		btc.run(argv[1]);
	}
	catch(const std::exception& e) 
	{
		std::cerr << e.what() << '\n';
		return 1;
	}

	return 0;	
}