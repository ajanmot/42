
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int range;
	int current;
	int i;

	if (min >= max)
		return (0);
	range = max - min;
	current = min;
	i = 0;
	tab = (int*)malloc(sizeof(*tab) * range);
	if (!tab)
		return (0);
	while (i < range)
	{
		tab[i] = current;
		current++;
		i++;
	}
	return (tab);
}
