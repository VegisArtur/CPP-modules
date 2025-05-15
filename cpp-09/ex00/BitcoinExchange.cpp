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



float BitcoinExchange::getRate(std::string inputDate)
{
	inputDate.erase(std::remove(inputDate.begin(), inputDate.end(), '-'), inputDate.end());
	std::map<std::string, float>::const_iterator it = rates.lower_bound(inputDate);

	if (it == rates.end() || it->first > inputDate)
	{
		if (it == rates.begin())
			throw std::runtime_error("No earlier exchange rate available.");
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

	int maxDay = monthDays[month - 1];

	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		maxDay = 29;

	if (day < 1 || day > maxDay)
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
		std::cout << "Error: too large a number => " << std::fixed << std::setprecision(0) << num << std::endl;
		return false;
	}
	return true;
}

bool BitcoinExchange::extractFloat(std::string &string, float &quantity)
{
	if (string.empty())
	{
		std::cout << "Error: input number invalid => [" << string << "]" << std::endl;
		return false;
	}

	std::stringstream ss(string);
	if (!(ss >> quantity))
		throw std::runtime_error("Failed to read stringstream, terminating program.");

	ss >> std::ws;
	if (ss.peek() != EOF)
	{
		std::cout << "Error: input number invalid => " << string << std::endl;
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
		if (line.empty())
			continue ;
		
		if (line.find('|') == std::string::npos)
		{
			std::cout << "Error: invalid input => " << line << std::endl;
			continue ;
		}

		line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
		std::string date = line.substr(0, line.find("|"));
		std::string quantityStr = line.substr(line.find("|") + 1);

		float quantity;
		if (extractFloat(quantityStr, quantity) == false)
			continue ;
		
		if (validateQuantity(quantity) == false)
			continue ;

		if (validateDate(date) == false)
			continue ;
		std::cout << date << " >> " << quantity << " = " << getRate(date) * quantity << std::endl;
	}
}