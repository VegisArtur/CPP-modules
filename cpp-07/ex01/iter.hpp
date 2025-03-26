#pragma once

#include <cstddef>
#include <iostream>

template<typename V, typename F>
void iter(V* arr, std::size_t len, F const f)
{
	for (std::size_t i = 0; i < len; i++)
		f(arr[i]);
}