#include <iostream>
#include "Array.hpp"

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

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
// 		// std::cout << "Array = [" << numbers[i] << "], Mirror = [" << mirror[i] << "]\n";
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }