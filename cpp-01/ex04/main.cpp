#include <iostream>
#include <fstream>
#include <string>

int	main(int argc, char **argv) {
	std::string fileName(argv[1]);
	std::string str1(argv[2]);
	std::string str2(argv[3]);

	std::ifstream file(fileName);
	if (file.is_open()) {
		std::string line;
		while (std::getline(file, line)) {

		}
		file.close();
	} else {
		std::cerr << "Unable to open file" << std::endl;
	}
}