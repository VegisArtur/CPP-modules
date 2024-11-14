#include <iostream>
#include <fstream>
#include <string>

int	main(int argc, char **argv) {
	if (argc != 4) {
		std::cout << "Invalid argument count!!" << std::endl;
		return (1);
	}
	std::string fileName(argv[1]);
	std::ifstream in(fileName);
	if (!in.is_open()) {
		std::cerr << "Unable to open read file" << std::endl;
		return (1);
	}
	std::ofstream out("output.txt", std::ios::out | std::ios::trunc);
	if (!out.is_open()) {
		std::cerr << "Unable to open file for writing!!" << std::endl;
		return (1);
	}
	std::string str1(argv[2]);
	std::string str2(argv[3]);
	std::string newString;
	std::string line;
	int			len = str1.length();
	char		ch;

	if (str1.empty())
	{
		while (in.get(ch))	{
			line += ch;
			if (ch == '\n')	{
				out << line;
				line.clear();
			}
		}
		if (!line.empty())	{
			out << line;
		}
	} else {
		while (in.get(ch))	{
			line += ch;
			if (ch == '\n')	{
				while (line.length() > 0) {
					size_t pos = line.find(str1);
					if (pos != std::string::npos) {
						newString = newString + line.substr(0, pos) + str2;
						line.erase(0, pos+len);
					} else {
						newString += line;
						break ;
					}
				}
				out << newString;
				line.clear();
				newString.clear();
			}
		}
		if (!line.empty())	{
			while (!line.empty()) {
				size_t pos = line.find(str1);
				if (pos != std::string::npos) {
					newString = newString + line.substr(0, pos) + str2;
					line.erase(0, pos+len);
				} else {
					newString += line;
					break ;
				}
			}
			out << newString;
		}
	}
	in.close();
	out.close();
	return (0);
}