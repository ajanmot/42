
int	ft_strcmp(char *s1, char *s2)
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
