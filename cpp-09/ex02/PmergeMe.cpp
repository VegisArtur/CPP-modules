#include "PmergeMe.hpp"

void PmergeMe::printVector()
{
	for (size_t i = 0; i < vectorSet.size(); ++i)
		std::cout << vectorSet[i] << " ";
	std::cout << std::endl;
}

void PmergeMe::insertVector(std::vector<int> &vec)
{
	for (size_t i = 1; i < vec.size(); ++i)
	{
		int key = vec[i];
		int j = i - 1;
		while (j >= 0 && vec[j] > key)
		{
			vec[j + 1] = vec[j];
			--j;
		}
		vec[j + 1] = key;
	}
}

void PmergeMe::sortVector(std::vector<int> &vec)
{
	if (vec.size() <= 1)
		return ;

	int mid = vec.size() / 2;
	std::vector<int> left(vec.begin(), vec.begin() + mid);
	std::vector<int> right(vec.begin() + mid, vec.end());

	sortVector(left);
	sortVector(right);

	vec.clear();
	vec.insert(vec.end(), left.begin(), left.end());
	vec.insert(vec.end(), right.begin(), right.end());

	insertVector(vec);
}

void PmergeMe::handleVector()
{
	std::cout << "Before = ";
	printVector();
	auto start = std::chrono::high_resolution_clock::now();
	sortVector(vectorSet);
	auto end = std::chrono::high_resolution_clock::now();
	std::cout << "After = ";
	printVector();
	std::chrono::duration<double> duration = end - start;

	std::cout << "Time to process a range of " << vectorSet.size()
		<< " elements with std::vector : "
		<< std::fixed << std::setprecision(5)
		<< duration.count() * 1e6 << " us" << std::endl;
}

void PmergeMe::insertDeque(std::deque<int>& left, std::deque<int>& right, std::deque<int>& deq)
{
	std::deque<int>::iterator itLeft = left.begin();
	std::deque<int>::iterator itRight = right.begin();

	while (itLeft != left.end() && itRight != right.end())
	{
		if (*itLeft < *itRight)
			deq.push_back(*itLeft++);
		else
			deq.push_back(*itRight++);
	}
	
	while (itLeft != left.end())
		deq.push_back(*itLeft++);
	while (itRight != right.end())
		deq.push_back(*itRight++);
}

void PmergeMe::sortDeque(std::deque<int> &deq)
{
	if (deq.size() <= 1)
		return ;

	size_t mid = deq.size() / 2;
	std::deque<int> left(deq.begin(), deq.begin() + mid);
	std::deque<int> right(deq.begin() + mid, deq.end());

	sortDeque(left);
	sortDeque(right);

	deq.clear();
	insertDeque(left, right, deq);
}

void PmergeMe::handleDeque()
{
	auto start = std::chrono::high_resolution_clock::now();
	sortDeque(dequeSet);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration = end - start;

	std::cout << "Time to process a range of " << vectorSet.size()
		<< " elements with std::deque : "
		<< std::fixed << std::setprecision(5)
		<< duration.count() * 1e6 << " us" << std::endl;
}