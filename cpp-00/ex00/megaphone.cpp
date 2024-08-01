#include <iostream>

int	main(int argc, char **argv)
{
	int i;

	i = 1;
	while (argv[i] != NULL)
	{
		while (*argv[i] != 0)
		{
			*argv[i] = *argv[i] + '32';
			*argv[i]++;
		}
		std::cout << argv[i];
		i++;
	}
	return (0);
}