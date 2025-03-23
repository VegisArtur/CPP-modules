#include "Data.hpp"

Data::Data() : i(5), chr('c') {}

Data::Data(Data const& other) : i(other.i), chr(other.chr) {}

Data::~Data() {}