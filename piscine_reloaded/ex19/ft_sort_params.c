
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

int		ft_strcmp(char *s1, char *s2)
{
	unsigned char a;
	unsigned char b;

	while (*s1 == *s2)
	{
		if (!*s1)
			break ;
		s1++;
		s2++;
	}
	a = *s1;
	b = *s2;
	if (a > b)
		return (1);
	else if (a < b)
		return (-1);
	else
		return (0);
}

int		main(int argc, char **argv)
{
	int		i;
	char	*tmp;
	int		counter;

	i = 1;
	counter = 1;
	while (i < argc - 1)
	{
		if (ft_strcmp(argv[i], argv[i + 1]) == 1)
		{
			tmp = argv[i];
			argv[i] = argv[i + 1];
			argv[i + 1] = tmp;
			i = 0;
		}
		i++;
	}
	while (counter < argc)
	{
		ft_putstr(argv[counter]);
		ft_putchar('\n');
		counter++;
	}
	return (0);
}
