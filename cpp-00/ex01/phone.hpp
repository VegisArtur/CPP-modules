#ifndef PHONE_HPP
#define PHONE_HPP
#include <iostream>

class contact
{
	public:
		std::string	name;
		std::string	lastname;
		std::string	nick;
		std::string	num;
		std::string	secret;
};

class book
{
	public:
		contact people[8];
		int		count;

	private:
		std::string pri;
};

void	add(book &book);

#endif