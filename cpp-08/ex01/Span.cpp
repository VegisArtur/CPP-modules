#include "Span.hpp"

Span::Span() : n(0) {}

Span::Span(unsigned int N) : n(N) {}

Span::Span(const Span& other) : n(other.n), numbers(other.numbers) {}

Span::~Span() {}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		this->n = other.n;
		this->numbers = other.numbers;
	}
	return *this;
}

void Span::addNumber(int number)
{
	if (numbers.size() >= n)
		throw std::out_of_range("Cannot add more numbers, Span is full.");
	numbers.push_back(number);
}

int Span::shortestSpan()
{
	if (numbers.size() < 2)
	throw std::logic_error("Not enough numbers to find a span.");
	
	std::vector<int> sortedNumbers = numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	
	int shortest = sortedNumbers[1] - sortedNumbers[0];
	for (size_t i = 1; i < sortedNumbers.size() - 1; ++i)
	{
		int span = sortedNumbers[i + 1] - sortedNumbers[i];
		if (span < shortest)
		shortest = span;
	}
	
	return shortest;
}

int Span::longestSpan()
{
	if (numbers.size() < 2)
	throw std::logic_error("Not enough numbers to find a span.");
	int minNum = *std::min_element(numbers.begin(), numbers.end());
	int maxNum = *std::max_element(numbers.begin(), numbers.end());
	
	return maxNum - minNum;
}

template <typename Iterator>
void Span::addRange(Iterator begin, Iterator end)
{
	size_t rangeSize = std::distance(begin, end);

	if (numbers.size() + rangeSize > n)
		throw std::out_of_range("Not enough space to add all numbers from the range.");
	numbers.insert(numbers.end(), begin, end);
}

template void Span::addRange<std::vector<int>::iterator>(std::vector<int>::iterator, std::vector<int>::iterator);