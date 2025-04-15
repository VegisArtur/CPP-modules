#include "Span.hpp"
#include <sstream>
#include <fstream>

std::vector<int> readNumbersFromFile(const std::string &filename)
{
	std::ifstream file(filename);
	std::vector<int> numbers;
	int number;

	if (!file.is_open())
		throw std::runtime_error("Could not open the file.");

	while (file >> number)
		numbers.push_back(number);

	file.close();
	return numbers;
}

int main()
{
	// Span sp = Span(5);
	Span sp = Span(10015);

	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e) {std::cerr << e.what() << std::endl;}

	std::cout << "---------- ||| ----------" << std::endl;
	
	try
	{
		std::vector<int> nums = {5, 15, 25, 35, 45};
		sp.addRange(nums.begin(), nums.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e) {std::cerr << e.what() << std::endl;}

	std::cout << "---------- ||| ----------" << std::endl;

	try
	{
		Span out(1);

		out.addNumber(10);
		std::cout << out.shortestSpan() << std::endl;
	}
	catch(const std::exception& e) {std::cerr << e.what() << std::endl;}

	std::cout << "---------- ||| ----------" << std::endl;
	
	try
	{
		std::vector<int> nums = readNumbersFromFile("numbers.txt");
		std::cout << nums.size() << std::endl;

		sp.addRange(nums.begin(), nums.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e) {std::cerr << e.what() << std::endl;}
	
	return 0;
}