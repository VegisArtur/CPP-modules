#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		void	cmd_add();
		void	cmd_search();

	private:
		Contact people[8];
		int		count;
		int		check_valid(std::string line);
		void	print_row(Contact person, int count);
		void	print_info(Contact person);
		void	get_info(std::string print, std::string &line);
		void	get_secret(std::string print, std::string &line);
		void	print_table();
};

#endif