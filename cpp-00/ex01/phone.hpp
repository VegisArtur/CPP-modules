#ifndef PHONE_HPP
#define PHONE_HPP
#include <iostream>

class Contact
{
	public:
		std::string	name;
		std::string	lastname;
		std::string	nick;
		std::string	num;
		std::string	secret;
};

class PhoneBook
{
	public:
		Contact people[8];
		int		count;

	private:
		std::string pri;
};

bool 	is_numeric(const std::string& line);
void	cmd_add(PhoneBook &book);

void	cmd_search(PhoneBook book, int count);

#endif