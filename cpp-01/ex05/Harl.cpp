#include "Harl.hpp"


void	Harl::debug( void ) {
	std::cout << "Factorio is a game about creating a factory in similar way like coding." << std::endl;
}

void	Harl::info( void ) {
	std::cout << "Factorio has function like production lines even if they arent functions." << std::endl;
}

void	Harl::warning( void ) {
	std::cout << "Production lines can turn into spaghetti and is inneficient but still works." << std::endl;
}

void	Harl::error( void ) {
	std::cout << "Multiple items were put on the same belt so the production has halted due to a deadlock!!" << std::endl;
}

typedef	void	(Harl::*message)( void );

void	Harl::complain( std::string level) {
	Harl msg;
	message debug = &Harl::debug;
	message info = &Harl::info;
	message warning = &Harl::warning;
	message error = &Harl::error;
	level == "debug" ? (msg.*debug)() : (level == "info" ? (msg.*info)() : (level == "warning" ? (msg.*warning)() : (level == "error" ? (msg.*error)() : void())));

}