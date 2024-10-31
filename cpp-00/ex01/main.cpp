#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main()
{
	std::string cmd;
	PhoneBook	book;

	while (1)
	{
		std::cout << std::endl << "Type a command" << std::endl << std::endl;
		std::cout << "ADD: Creates a new contact" << std::endl;
		std::cout << "SEARCH: Displays all your contacts" << std::endl;
		std::cout << "EXIT: Leaves the phonebook" << std::endl << std::endl;
		std::getline(std::cin, cmd);
		if (std::cin.eof())
			break;
		if (cmd == "ADD")
			book.cmd_add();
		if (cmd == "SEARCH")
			book.cmd_search();
		if (cmd == "EXIT")
			break ;
	}
	return (0);
}