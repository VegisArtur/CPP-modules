#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137)
{	
}

void ShrubberyCreationForm::executeForm() const
{
	std::ofstream file(getName() + "_shrubbery");
	if (!file)
	{
		std::cerr << "File error!" << std::endl;
		return ;
	}

	file << "       _-_" << std::endl;
	file << "    /~~   ~~\\ " << std::endl;
	file << " /~~         ~~\\ " << std::endl;
	file << "{               }" << std::endl;
	file << " \\  _-     -_  /" << std::endl;
	file << "   ~  \\ //  ~" << std::endl;
	file << "_- -   | | _- _" << std::endl;
	file << "  _ -  | |   -_" << std::endl;
	file << "      // \\" << std::endl;

	file.close();
}

/*
       _-_
    /~~   ~~\
 /~~         ~~\
{               }
 \  _-     -_  /
   ~  \\ //  ~
_- -   | | _- _
  _ -  | |   -_
      // \\

*/