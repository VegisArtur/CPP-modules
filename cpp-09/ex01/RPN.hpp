#pragma once

#include <stack>
#include <iostream>
#include <sstream>
#include <cctype>

const std::string validNum = "+-/* 0123456789";

class RPN
{
	private:
		std::stack<int> num;
	
	public:
		RPN();
		RPN(const RPN &other);
		RPN& operator=(const RPN &other);
		~RPN();
		void calculate(std::string argument);
		bool validate(const std::string &argument) const;
};