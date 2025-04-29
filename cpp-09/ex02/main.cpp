#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Usage: " << argv[0] << " <sequence of positive integers>" << std::endl;
		return false;
	}

	std::vector<int> vecInput;
	std::deque<int> dequeInput;
	for (int i = 1; i < argc; ++i)
	{
		int val = std::stoi(argv[i]);
		if (val < 0)
		{
			std::cerr << "Error: only positive integers allowed." << std::endl;
			return false;
		}
		vecInput.push_back(val);
		dequeInput.push_back(val);

	}
	std::cout << "Sorting: ";
	for (size_t i = 0; i < dequeInput.size(); ++i) std::cout << dequeInput[i] << " ";
		std::cout << std::endl;
	
	PmergeMe algorithm(vecInput, dequeInput);
}