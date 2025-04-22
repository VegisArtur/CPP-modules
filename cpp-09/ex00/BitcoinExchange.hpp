#pragma once

#include <iostream>
#include <string>
#include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, float> rates;
	
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange& operator=(const BitcoinExchange &other);
		~BitcoinExchange();

};