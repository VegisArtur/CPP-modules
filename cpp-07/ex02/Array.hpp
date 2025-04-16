#pragma once

#include <exception>
#include <stdexcept>

template<class T>
class Array
{
	public:
		Array()
		{
			array = NULL;
			len = 0;
		}

		Array(unsigned int n)
		{
			array = new T[n]();
			len = n;
		}
		
		Array(Array const &other)
		{
			len = other.len;
			array = new T[other.len]();
			for (unsigned int i = 0; i < other.len; i++)
				array[i] = other.array[i];
		}

		Array operator=(Array const &other)
		{
			if (this != &other)
			{
				if (array)
					delete[] array;
				len = other.len;
				array = new T[other.len]();
				for (unsigned int i = 0; i < other.len; i++)
					array[i] = other.array[i];
			}
			return (*this);
		}
		
		~Array()
		{
			if (array)
				delete[] array;	
		}

		T& operator[](int i)
		{
			if (i >= static_cast<int>(len) || i < 0)
				throw (std::out_of_range("Index out of bounds!!"));
			return (array[i]);
		}

		const T& operator[](int i) const
		{
			if (i >= static_cast<int>(len) || i < 0)
				throw (std::out_of_range("Index out of bounds!!"));
			return (array[i]);
		}

		int size() {return len;}

	private:
		T*	array;
		unsigned int	len;
};