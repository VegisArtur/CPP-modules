#include "phone.hpp"
#include <string>
#include <iomanip>

void	print_set(std::string str)
{
	if (str.length() <= 10)
		std::cout << "|" << std::right << std::setw(10) << str.substr(0, 10);
	else
		std::cout << "|" << std::right << std::setw(9) << str.substr(0, 9) << '.';
}

void	print_row(Contact person, int count)
{
	std::cout << "|" << std::right << std::setw(10) << (count);
	print_set(person.name);
	print_set(person.lastname);
	print_set(person.nick);
	std::cout << "|" << std::endl;
}

void	print_table(PhoneBook book, int count)
{
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	if (count >= 9)
		for (int i = 0; i < 8; i++)
			print_row(book.people[((count + i) % 8)], i + 1);
	else
		for (int i = 0; i < 8; i++)
			print_row(book.people[i], i + 1);
}

void	print_info(Contact person)
{
	std::cout << "Name = " << person.name << std::endl;
	std::cout << "Last Name = " << person.lastname << std::endl;
	std::cout << "Nickname = " << person.nick << std::endl;
	std::cout << "Number = " << person.num << std::endl;
	std::cout << "Darkest Secret = " << person.secret << std::endl;
}

void	cmd_search(PhoneBook book, int count)
{
	std::string line;
	int value = 0;
	if (count == 0)
	{
		std::cout << "No contacts to view!!" << std::endl;
		return ;
	}
	print_table(book, count);
	while (1)
	{
		std::getline(std::cin, line);
		if (line.empty() == false && is_numeric(line) == true)
			value = std::stoi(line);
		if ((value < 1 || value > 8) || (count < 8 && value > count))
		{
			std::cout << "Invalid input!!" << std::endl;
			if (count > 8)
				std::cout << "Please use 1 to 8" << std::endl;
			else
				std::cout << "Please use 1 to " << std::to_string(count) << std::endl;
			continue ;
		}
		break ;
	}
	if (count < 8)
		{
			print_info(book.people[value - 1]);
			return ;
		}
	print_info(book.people[(count + value - 1) % 8]);
}