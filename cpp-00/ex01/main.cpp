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
		std::cout << "SEARCH: Displays all your contacts" << std::endl;
		std::cout << "EXIT: Leaves the phonebook" << std::endl << std::endl;
		std::getline(std::cin, cmd);
		if (std::cin.eof())
			break;
		if (cmd == "ADD")
			cmd_add(book);
		if (cmd == "SEARCH")
			cmd_search(book, book.count);
		if (cmd == "EXIT")
			break ;
		// if (cmd == "ADD1")
		// {
		// 	for (int i = 0; i < 8; i++)
		// 	{
		// 		book.people[book.count % 8].name = "add" + std::to_string(i+1);
		// 		book.people[book.count % 8].lastname = "add" + std::to_string(i+1);
		// 		book.people[book.count % 8].nick = "add" + std::to_string(i+1);
		// 		book.people[book.count % 8].num = "123" + std::to_string(i+1);
		// 		book.people[book.count % 8].secret = "add" + std::to_string(i+1);
		// 		book.count++;
		// 	}
		// }
	}
	return (0);
}