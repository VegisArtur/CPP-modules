#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data data;

    std::cout << &data << std::endl;
    std::cout << Serializer::deserialize(Serializer::serialize(&data)) << std::endl;

	std::cout << "---------- ||| ----------" << std::endl;

	uintptr_t serializedValue = Serializer::serialize(&data);

	std::cout << &data << std::endl;
	std::cout << serializedValue << std::endl;
	std::cout << Serializer::deserialize(serializedValue) << std::endl;

    return 0;
}