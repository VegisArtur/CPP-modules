#include "iter.hpp"

// template<typename V>
// void f(V& x)
// {
// 	std::cout << "input: " << x << std::endl;
// 	x += 1;
// 	std::cout << "output: " << x << std::endl;
// }

template<typename V>
void f(const V& x)
{
	std::cout << "Content: " << x << std::endl;
}

int main()
{
	char arr[5] = {'a', 'b', 'c', 'd', 'e'};
	iter(arr, 5, f<char>);

	std::cout << std::endl;

	int array[10] = {9, 6, 7, 3, 2, 1, 5, 4, 3, 8};
	iter(array, 10, f<int>);

	std::cout << std::endl;

	const int num[5] = {1, 3, 5, 2, 4};
	iter(num, 5, f<const int>);
	return 0;
}