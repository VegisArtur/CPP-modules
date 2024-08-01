#include <iostream>

int	main(int argc, char **argv)
{
	int i = 1;
	int j = 0;

	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != 0)
		{
			argv[i][j] = std::toupper(argv[i][j]);
			j++;
		}
		std::cout << argv[i];
		i++;
	}
	std::cout << std::endl;
	return (0);
}