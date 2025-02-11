#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat b1(10, "Bob");
	Form easyForm("Easy form", 12, 5);
	Form hardForm("Hard form", 5, 5);

	std::cout << "---------- ||| ----------" << std::endl;

	std::cout << easyForm;

	std::cout << "---------- ||| ----------" << std::endl;

	b1.signForm(easyForm);
	b1.signForm(hardForm);

	std::cout << "---------- ||| ----------" << std::endl;

	while (b1.getGrade() > 5)
		b1.incrementGrade();
	std::cout << b1;
	b1.signForm(hardForm);

	std::cout << "---------- ||| ----------" << std::endl;

	std::cout << easyForm;

	std::cout << "---------- ||| ----------" << std::endl;

	try {Form impossibleForm("imp", 170, 5);}
	catch(const std::exception& e) {std::cerr << e.what() << std::endl;}

	try {Form impossibleForm("imp", 5, 170);}
	catch(const std::exception& e) {std::cerr << e.what() << std::endl;}

	try {Form impossibleForm("imp", 0, 5);}
	catch(const std::exception& e) {std::cerr << e.what() << std::endl;}

	try {Form impossibleForm("imp", 5, 0);}
	catch(const std::exception& e) {std::cerr << e.what() << std::endl;}

	return 0;
}