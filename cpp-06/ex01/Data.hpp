#pragma once

class Data
{
	public:
		int const	i;
		char const	chr;

		Data();
		Data(Data const& other);
		~Data();

	private:

		Data&  operator=(Data const& other);
};