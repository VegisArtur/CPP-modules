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
	std::map<std::string, float>::const_iterator it = rates.lower_bound(inputDate);

	if (it == rates.end() || it->first > inputDate)
	{
		if (it == rates.begin())
			throw std::runtime_error("No earlier echange rate available.");
		--it;
	}
	return it->second;
}

bool BitcoinExchange::validateDate(const std::string &inputDate) const
{
	if (inputDate.length() != 10 || inputDate[4] != '-' || inputDate[7] != '-')
	{
		std::cout << "Error: Bad input => " << inputDate << std::endl;
		return false;
	}

	std::string date = inputDate;
	int year, month, day;
	char dash;

	std::stringstream ss(date);
	ss >> year >> dash >> month >> dash >> day;

	if (ss.fail() || year < MINYEAR || year > MAXYEAR || month < 1 || month > 12)
	{
		std::cout << "Error: Bad input => " << inputDate << std::endl;
		return false;
	}

	if (day < 1 || day > monthDays[month - 1])
	{
		std::cout << "Error: Bad input => " << inputDate << std::endl;
		return false;
	}

	return true;
}

bool BitcoinExchange::validateQuantity(const float &num) const
{
	if (num < 0)
	{
		std::cout << "Error: not a positive number => " << num << std::endl;
		return false;
	}

	if (num > maxInput)
	{
		std::cout << "Error: too large a number => " << num << std::endl;
		return false;
	}
	return true;
}

void BitcoinExchange::run(std::string file)
{
	std::ifstream data(file);
	if (!data)
		throw(std::logic_error("Couldnt open " + file));

	std::string line;
	std::getline(data, line);
	while (std::getline(data, line))
	{
		line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
		if (line.empty()) // || line.find("|") == std::string::npos
			continue ;
		
		std::string date = line.substr(0, line.find("|"));
		std::string quantityStr = line.substr(line.find("|") + 1);

		std::stringstream ss(quantityStr);
		float quantity;
		ss >> quantity;

		if (validateQuantity(quantity) == false)
			continue ;

		// std::cout << "Inserting " << date << " + " << quantity << "\n" << std::endl;
		if (validateDate(date) == false)
			continue ;
		std::cout << date << " >> " << quantity << " = " << getRate(date) * quantity << std::endl;
	}

	for (auto it = input.begin(); it != input.end(); ++it)
	{
		std::cout << it->first << " >> " << it->second << std::endl;
	}
}