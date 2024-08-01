#include "phone.hpp"
#include <string>
#include <cctype>

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

// int	get_info_num(std::string print)
// {
// 	std::string	line;
// 	int			num;

// 	std::cout << print << std::endl;
// 	while (1)
// 	{
// 		std::getline(std::cin, line);
// 		num = std::stoi(line);
// 		std::cout << "Invalid input, try again" << std::endl;
// 	}
// 	return (0);
// }

std::string	get_info(std::string print, int flag)
{
	std::string	line;

	std::cout << print << std::endl;
	while (1)
	{
		std::getline(std::cin, line);
		if (flag == 1)
			return (line);
		if (check_valid(line) == 0)
			return (line);
		std::cout << "Invalid input, try again" << std::endl;
	}
	return (NULL);
}

void	add(book book)
{
	(void)book;
	contact		contact;
	std::string	line;

	contact.name = get_info("Specify a name", 0);
	contact.lastname = get_info("Specify a last name", 0);
	contact.nick = get_info("Specify a nickname", 0);
	// contact.num = get_info_num("Specify the number");
	contact.secret = get_info("Darkest secret ;)", 1);
}