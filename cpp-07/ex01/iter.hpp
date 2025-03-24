#pragma once

#include <cstddef>
#include <iostream>

template<typename V, typename F>
void iter(V* arr, std::size_t len, F f)
{
	for (std::size_t i = 0; i < len; i++)
		f(arr[i]);
}

template<typename V>
void f(V& x)
{
	std::cout << "input: " << x << std::endl;
	x += 1;
	std::cout << "output: " << x << std::endl;
}