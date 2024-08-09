#include "Harl.hpp"

typedef	void	(Harl::*message)( void );

void	Harl::complain( std::string level) {
	message x = &Harl::debug;
	switcch (level)
	{
		case "debug": 
		{

		}
		break;

		case "info"
		{

		}
		break;

		default:
		{

		}
		break;

	}
}

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