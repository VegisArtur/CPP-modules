#include "Contact.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : count(0)
{
}

int	PhoneBook::check_valid(std::string line)
{
	size_t pos = line.find(' ');
	if (pos == std::string::npos)
	{
		if (line.length() >= 1)
			return (0);
		else
		{
			std::cout << "Invalid input!!" << std::endl << "Input can't be empty.." << std::endl;
			return (1);
		}
	}
	else
	{
		std::cout << "Invalid input!!" << std::endl << "Try again without spaces.." << std::endl;
		return (1);
	}
	return (-1);
}

void	PhoneBook::get_info(std::string print, std::string &line)
{
	std::cout << print << std::endl;
	while (1)
	{
		std::getline(std::cin, line);
		if (std::cin.eof())
			return ;
		if (check_valid(line) == 0)
			return ;
	}
}
void	PhoneBook::get_secret(std::string print, std::string &line)
{
	std::cout << print << std::endl;
	std::getline(std::cin, line);
}


void	PhoneBook::cmd_add()
{
	get_info("Specify a name", people[count % 8].get_name());
	get_info("Specify a last name", people[count % 8].get_lastname());
	get_info("Specify a nickname", people[count % 8].get_nick());
	get_info("Specify the number", people[count % 8].get_num());
	get_secret("Darkest secret)", people[count % 8].get_secret());
	count++;
}

void	PhoneBook::print_row(Contact person, int index)
{
	std::cout << "|" << std::right << std::setw(10) << (index);
	person.print_set(person.get_name());
	person.print_set(person.get_lastname());
	person.print_set(person.get_nick());
	std::cout << "|" << std::endl;
}

void	PhoneBook::print_table()
{
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	if (count >= 9)
		for (int i = 0; i < 8; i++)
			print_row(people[((count + i) % 8)], i + 1);
	else
		for (int i = 0; i < 8; i++)
			print_row(people[i], i + 1);
}

void	PhoneBook::print_info(Contact person)
{
	std::cout << "Name = " << person.get_name() << std::endl;
	std::cout << "Last Name = " << person.get_lastname() << std::endl;
	std::cout << "Nickname = " << person.get_nick() << std::endl;
	std::cout << "Number = " << person.get_num() << std::endl;
	std::cout << "Darkest Secret = " << person.get_secret() << std::endl;
}

void	PhoneBook::cmd_search()
{
	std::string line;
	int value = 0;
	if (count == 0)
	{
		std::cout << "No contacts to view!!" << std::endl;
		return ;
	}
	print_table();
	while (1)
	{
		std::getline(std::cin, line);
		if (std::cin.eof())
			return;
		if (line.empty() == false)
		try {
			value = std::stoi(line);
		} catch (const std::invalid_argument& e) {
			std::cout << "Invalid input!!" << std::endl << "Please use a number" << std::endl;
			continue;
		} catch (const std::out_of_range& e) {
			std::cout << "Invalid input!!" << std::endl;
			if (count > 8)
				std::cout << "Please use 1 to 8" << std::endl;
			else
				std::cout << "Please use 1 to " << std::to_string(count) << std::endl;
			continue;
		}
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
			print_info(people[value - 1]);
			return ;
		}
	print_info(people[(count + value - 1) % 8]);
}