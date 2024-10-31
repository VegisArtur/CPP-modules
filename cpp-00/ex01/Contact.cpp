#include "Contact.hpp"
#include "PhoneBook.hpp"

void	Contact::print_set(std::string str)
{
	if (str.length() <= 10)
		std::cout << "|" << std::right << std::setw(10) << str.substr(0, 10);
	else
		std::cout << "|" << std::right << std::setw(9) << str.substr(0, 9) << '.';
}

void	Contact::set_name(std::string str)
{
	name = str;
}

void	Contact::set_lastname(std::string str)
{
	lastname = str;
}

void	Contact::set_nick(std::string str)
{
	nick = str;
}

void	Contact::set_num(std::string str)
{
	num = str;
}

void	Contact::set_secret(std::string str)
{
	secret = str;
}

std::string&	Contact::get_name()
{
	return (name);
}

std::string&	Contact::get_lastname()
{
	return (lastname);
}

std::string&	Contact::get_nick()
{
	return (nick);
}

std::string&	Contact::get_num()
{
	return (num);
}

std::string&	Contact::get_secret()
{
	return (secret);
}