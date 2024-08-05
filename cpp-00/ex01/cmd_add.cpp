#include "phone.hpp"
#include <string>
#include <cctype>
#include <algorithm>

int	check_valid(std::string line)
{
	size_t pos = line.find(' ');
	if (pos == std::string::npos)
		return (0);
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

void	get_info(std::string print, std::string &line)
{
	std::cout << print << std::endl;
	while (1)
	{
		std::getline(std::cin, line);
		if (check_valid(line) == 0)
			return ;
		std::cout << "Invalid input!!" << std::endl << "Try again without spaces.." << std::endl;
	}
}
void	get_secret(std::string print, std::string &line)
{
	std::cout << print << std::endl;
	std::getline(std::cin, line);
}

void	get_num(std::string print, std::string &line)
{
	std::cout << print << std::endl;
	while (1)
	{
		std::getline(std::cin, line);
		if (is_numeric(line) == true)
			return ;
		std::cout << "Invalid input!!" << std::endl << "Try again with only numbers." << std::endl;
	}
}

void	cmd_add(PhoneBook &book)
{
	get_info("Specify a name", book.people[book.count % 8].name);
	get_info("Specify a last name", book.people[book.count % 8].lastname);
	get_info("Specify a nickname", book.people[book.count % 8].nick);
	get_num("Specify the number", book.people[book.count % 8].num);
	get_secret("Darkest secret)", book.people[book.count % 8].secret);
	book.count++;
}