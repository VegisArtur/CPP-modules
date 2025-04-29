#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <chrono>
#include <iomanip>

class PmergeMe
{
	private:
		std::vector<int> vectorSet;
		std::deque<int> dequeSet;
		
		void insertVector(std::vector<int> &vec);
		void insertDeque(std::deque<int>& left, std::deque<int>& right, std::deque<int>& deq);
		void sortVector(std::vector<int> &vec);
		void sortDeque(std::deque<int> &deq);
		void printVector();
		void printDeque();
		void handleVector();
		void handleDeque();

	public:
		PmergeMe() {};
		PmergeMe(const PmergeMe &other) : vectorSet(other.vectorSet), dequeSet(other.dequeSet) {};
		PmergeMe& operator=(const PmergeMe &other)
		{
			if (this != &other)
			{
				vectorSet = other.vectorSet;
				dequeSet = other.dequeSet;
			}
			return *this;
		}
		~PmergeMe() {}

		PmergeMe(std::vector<int> vec, std::deque<int> deq) : vectorSet(vec), dequeSet(deq)
		{
			handleVector();
			handleDeque();
		};
};