#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data data;

    std::cout << &data << "\n";
    std::cout << Serializer::deserialize(Serializer::serialize(&data)) << "\n";

	// Serializer test;
    return 0;
}