
#include "ft_display_file.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		write(2, "File name missing.\n", 19);
		return (0);
	}
	else if (argc == 3)
	{
		write(2, "Too many arguments.\n", 20);
		return (0);
	}
	else
	{
		ft_display_file(argv[1]);
		return (0);
	}
}
