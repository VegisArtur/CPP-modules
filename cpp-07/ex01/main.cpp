#include "iter.hpp"

int main()
{
	char arr[5] = {'a', 'b', 'c', 'd', 'e'};
	iter<char>(arr, 5, f<char>);

	int array[10] = {4, 2, 1, 6, 3, 7, 8, 9, 3, 5};
	iter<int>(array, 10, f<int>);
	return 0;
}