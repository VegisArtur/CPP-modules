#pragma once

#include <iostream>
#include <string>
#include <map>

#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stdexcept>

class BitcoinExchange
{
	private:
		std::map<std::string, float> rates;
	
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange& operator=(const BitcoinExchange &other);
		~BitcoinExchange();
		float getRate(const std::string &inputDate) const;

};