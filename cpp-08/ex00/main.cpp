#include <iostream>
#include <vector>
#include <list>
#include <map>
#include "easyfind.hpp"

int main() {
	std::vector<int> vec = {1, 3, 5, 7, 9};

	try
	{
		auto it = easyfind(vec, 5);
		std::cout << "Found in vector: " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Vector Error: " << e.what() << std::endl;
	}

	try
	{
		auto it = easyfind(vec, 10);
		std::cout << "Found in vector: " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Vector Error: " << e.what() << std::endl;
	}

	std::list<int> lst = {2, 4, 6, 8};

	try
	{
		auto it = easyfind(lst, 4);
		std::cout << "Found in list: " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "List Error: " << e.what() << std::endl;
	}

	return 0;
}
