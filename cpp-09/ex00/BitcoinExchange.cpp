#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() 
{
	std::ifstream data("data.csv");
	if (!data)
		throw(std::logic_error("Couldnt open data.csv"));

	std::string date;
	float price;
	std::getline(data, date);
	while (std::getline(data, date))
	{
		if (date.find(",") == std::string::npos)
			continue ;
		std::stringstream(date.c_str() + date.find(",") + 1) >> price;
		date.erase(date.find(","));
		date.erase(std::remove(date.begin(), date.end(), '-'), date.end());
		rates.insert(std::map<std::string, float>::value_type(date, price));
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other) {}

BitcoinExchange::~BitcoinExchange() {}