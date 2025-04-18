#include "Span.hpp"
#include <random>

int main()
{
	Span sp = Span(15);

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
		const size_t n = 50000;
		std::vector<int> nums;
		nums.reserve(n);

		std::random_device rd;
		std::mt19937 gen(rd()); // Mersenne Twister engine
		std::uniform_int_distribution<> dist(1, 1000000);

		for (size_t i = 0; i < n; ++i)
			nums.push_back(dist(gen));
		std::cout << "Generated " << nums.size() << " numbers." << std::endl;

		Span huge(n);
		huge.addRange(nums.begin(), nums.end());
		std::cout << huge.shortestSpan() << std::endl;
		std::cout << huge.longestSpan() << std::endl;
	}
	catch(const std::exception& e) {std::cerr << e.what() << std::endl;}
	
	return 0;
}