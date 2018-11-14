/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 20:12:46 by ajanmot           #+#    #+#             */
/*   Updated: 2017/11/17 08:56:45 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_put_a(long value, char **result, int *current)
{
	char *tmp;

	tmp = *result;
	tmp[*current] = value + '0';
	(*current)++;
}

static void		ft_putnbr_itoa(long value, char **result, int *current)
{
	if (value >= 10)
	{
		ft_putnbr_itoa(value / 10, result, current);
		value %= 10;
	}
	ft_put_a(value, result, current);
}

static int		ft_getsize(int n)
{
	long	nb_long;
	int		size;

	size = 1;
	nb_long = n;
	if (nb_long < 0)
		nb_long = -nb_long;
	while (nb_long >= 10)
	{
		nb_long /= 10;
		size++;
	}
	return (n < 0 ? size + 2 : size + 1);
}

char			*ft_itoa(int n)
{
	char	*result;
	int		current;
	long	n_long;

	if (!(result = (char *)malloc(sizeof(char) * ft_getsize(n))))
		return (NULL);
	current = 0;
	n_long = n;
	if (n < 0)
	{
		result[current] = '-';
		current++;
		n_long = -n_long;
	}
	ft_putnbr_itoa(n_long, &result, &current);
	result[current] = '\0';
	return (result);
}
