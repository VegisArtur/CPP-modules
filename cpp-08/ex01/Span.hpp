#pragma once

#include <vector>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <iterator>

class Span
{
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &other);
		~Span();
		Span& operator=(const Span& ref);
		void addNumber(int number);
		int shortestSpan();
		int longestSpan();

		template <typename Iterator>
		void addRange(Iterator begin, Iterator end);

	private:
		unsigned int n;
		std::vector<int> numbers;
};