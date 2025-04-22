#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() 
{
	std::ifstream data("data.csv");
	if (!data)
		throw(std::logic_error("Couldnt open data.csv"));

	std::string line;
	std::getline(data, line);

	while (std::getline(data, line))
	{
		if (line.find(",") == std::string::npos)
			continue ;
		
		std::string date = line.substr(0, line.find(","));
		std::string priceStr = line.substr(line.find(",") + 1);

		std::stringstream ss(priceStr);
		float price;
		ss >> price;

		date.erase(std::remove(date.begin(), date.end(), '-'), date.end());

		rates[date] = price;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : rates(other.rates) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other) 
{
	if (this != &other)
		rates = other.rates;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

float BitcoinExchange::getRate(const std::string &inputDate) const
{
	std::string date = inputDate;
	date.erase(std::remove(date.begin(), date.end(), '-'), date.end());

	std::map<std::string, float>::const_iterator it = rates.lower_bound(date);

	if (it == rates.end() || it->first > date)
	{
		if (it == rates.begin())
			throw std::runtime_error("No earlier echange rate available.");
		--it;
	}
	return it->second;
}