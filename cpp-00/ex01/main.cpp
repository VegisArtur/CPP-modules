#include "phone.hpp"

int	main()
{
	std::string cmd;
	PhoneBook	book;
	book.count = 0;

	while (1)
	{
	std::cout << std::endl << "Type a command" << std::endl << std::endl;
	std::cout << "ADD: Creates a new contact" << std::endl;
	std::cout << "SEARCH: displays all your contacts" << std::endl;
	std::cout << "EXIT: leaves the phonebook" << std::endl << std::endl;
	std::getline(std::cin, cmd);
	if (cmd == "ADD")
		cmd_add(book);
	if (cmd == "SEARCH")
		cmd_search(book);
	if (cmd == "EXIT")
		break ;
	if (cmd == "DEBUG")
		std::cout << book.people[0].name << std::endl << book.people[0].lastname << std::endl;
	}
	return (0);
}