
int	ft_count_if(char **tab, int (*f)(char*))
{
	int i;
	int counter;

	i = 0;
	counter = 0;
	while (tab[i] != 0)
	{
		if (f(tab[i]) == 1)
			counter++;
		i++;
	}
	return (counter);
}
