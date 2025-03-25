#include "Array.hpp"
#include <iostream>

int main()
{
	int quant = 5;
	Array<int> arr(quant);
	try
	{
		for (int i = 0; i < quant; i++)
			std::cout << "Element " << i + 1 << " = " << arr[i] << std::endl;
		std::cout << std::endl;
		for (int i = 0; i < quant; i++)
			arr[i] = i*2;
		for (int i = 0; i < quant; i++)
			std::cout << "Element " << i + 1 << " = " << arr[i] << std::endl;
		std::cout << std::endl;
		// std::cout << arr[quant+1] << std::endl;
		// std::cout << arr[-10] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	Array<int> arr2;
	arr2 = arr;
	for (int i = 0; i < quant; i++)
			arr2[i] += 10;
	for (int i = 0; i < quant; i++)
	{
		std::cout << "Arr1 " << i + 1 << " = " << arr[i] << std::endl;
		std::cout << "Arr2 " << i + 1 << " = " << arr2[i] << std::endl;
		std::cout << std::endl;
	}

	const Array<int> arr3(arr);
	for (int i = 0; i < quant; i++)
		std::cout << "Element " << i + 1 << " = " << arr3[i] << std::endl;

	return (0);
}