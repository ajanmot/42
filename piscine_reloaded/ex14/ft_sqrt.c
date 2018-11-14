
int	ft_sqrt(int nb)
{
	long long count;

	count = 1;
	if (nb < 1)
		return (0);
	while (count * count < nb)
		count++;
	if (count * count == nb)
		return (count);
	else
		return (0);
}
