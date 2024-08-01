#include <iostream>

using namespace std;

int	main(int argc, char **argv)
{
	int i = 1;
	int j = 0;

	(void)argc;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != 0)
		{
			argv[i][j] = toupper(argv[i][j]);
			j++;
		}
		cout << argv[i];
		i++;
	}
	cout << endl;
	return (0);
}