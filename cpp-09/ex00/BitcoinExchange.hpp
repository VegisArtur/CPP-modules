#pragma once

#include <iostream>
#include <string>
#include <map>

#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stdexcept>
#include <iomanip>

const int MAXYEAR = 2024;
const int MINYEAR = 2008;
const int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int maxInput = 1000;

class BitcoinExchange
{
	private:
		std::map<std::string, float> rates;
	
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange& operator=(const BitcoinExchange &other);
		~BitcoinExchange();
		float getRate(std::string inputDate);
		bool validateDate(const std::string &inputDate) const;
		bool validateQuantity(const float &num) const;
		bool extractFloat(std::string &string, float &quantity);
		void run(std::string file);
};