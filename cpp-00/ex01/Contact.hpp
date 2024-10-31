#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>

class Contact
{
	public:
		void			print_set(std::string str);
		void			set_name(std::string str);
		void			set_lastname(std::string str);
		void			set_nick(std::string str);
		void			set_num(std::string str);
		void			set_secret(std::string str);
		std::string&	get_name();
		std::string&	get_lastname();
		std::string&	get_nick();
		std::string&	get_num();
		std::string&	get_secret();

	private:
		std::string		name;
		std::string		lastname;
		std::string		nick;
		std::string		num;
		std::string		secret;
	
};

#endif