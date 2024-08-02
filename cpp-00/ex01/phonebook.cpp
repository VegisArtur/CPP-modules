#include "phone.hpp"
#include <string>
#include <cctype>
#include <algorithm>

int	check_valid(std::string line)
{
	size_t pos = line.find(' ');
	if (pos == std::string::npos)
	{
		std::cout << "valid input" << std::endl;
		return (0);
	}
	else
		return (1);
	return (-1);
}

bool is_numeric(const std::string& line) 
{
    return std::all_of(line.begin(), line.end(), [](char c)
	{
		return std::isdigit(c);
	});
}

int	get_info_num(std::string print, int &num)
{
	std::string	line;

	std::cout << print << std::endl;
	while (1)
	{
		std::cin.width(11);
		std::getline(std::cin, line);

		if (is_numeric(line) == true)
			num = std::stoi(line);
		std::cout << "Invalid input, try again" << std::endl;
	}
	return (0);
}

void	get_info(std::string print, int flag, std::string &line)
{
	std::cout << print << std::endl;
	while (1)
	{
		std::getline(std::cin, line);
		if (flag == 1)
			return ;
		if (flag == 2 && is_numeric(line) == true)
			return ;
		if (flag == 0 && check_valid(line) == 0)
			return ;
		std::cout << "Invalid input!!" << std::endl;
		if (flag == 2)
		{
			std::cout << "Try again with only numbers." << std::endl;
			continue ;
		}
		std::cout << "Try again without spaces.." << std::endl;
	}
}

void	add(book &book)
{
	get_info("Specify a name", 0, book.people[book.count % 8].name);
	get_info("Specify a last name", 0, book.people[book.count % 8].lastname);
	get_info("Specify a nickname", 0, book.people[book.count % 8].nick);
	get_info("Specify the number", 2, book.people[book.count % 8].num);
	get_info("Darkest secret)", 1, book.people[book.count % 8].secret);
	book.count++;
}