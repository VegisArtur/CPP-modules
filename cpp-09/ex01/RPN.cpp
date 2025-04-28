#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other) : num(other.num) {}

RPN& RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		num = other.num;
	}
	return *this;
}

RPN::~RPN() {}

bool RPN::validate(const std::string &argument) const
{
	if (argument.find_first_not_of(validNum) != std::string::npos)
		return false;

	std::stringstream iss(argument);
	std::string token;
	int operandCount = 0;

	while (iss >> token)
	{
		if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (operandCount < 2)
				return false;
			operandCount--;
		}
		else
		{
			if (token.length() != 1 || !std::isdigit(token[0]))
				return false;
			operandCount++;
		}
	}

	return (operandCount == 1);
}

void RPN::calculate(std::string argument)
{
	if (!validate(argument))
	{
		std::cout << "Invalid arguments!!" << std::endl;
		return ;
	}

	std::stringstream iss(argument);
	std::string token;

	while (iss >> token)
	{
		if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			int b = num.top(); num.pop();
			int a = num.top(); num.pop();
			if (token == "+") num.push(a + b);
			else if (token == "-") num.push(a - b);
			else if (token == "*") num.push(a * b);
			else if (token == "/") num.push(a / b);
		}
		else
		num.push(std::stoi(token));
	}
	std::cout << num.top() << std::endl;
}