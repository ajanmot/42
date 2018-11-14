
void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		main(int argc, char **argv)
{
	int current;

	current = 1;
	while (current < argc)
	{
		ft_putstr(argv[current]);
		current++;
		ft_putchar('\n');
	}
	return (0);
}
