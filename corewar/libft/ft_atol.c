/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 20:23:02 by tkeynes           #+#    #+#             */
/*   Updated: 2018/03/30 20:33:56 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <limits.h>

int		ft_isspace(int c)
{
	c = (unsigned char)c;
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' ||
c == ' ')
		return (1);
	return (0);
}

long	ft_atol_no_limit(const char *str)
{
	long int	nb;
	int			sign;

	nb = 0;
	sign = 1;
	while (ft_isspace((int)*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = (-1);
		str++;
	}
	while (ft_isdigit((int)*str))
	{
		nb = nb * 10 + *str - '0';
		str++;
	}
	return (sign * nb);
}

int		str_num_length(const char *str)
{
	int counter;

	counter = 0;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (counter);
		counter++;
		str++;
	}
	return (counter);
}

long	ft_ok(const char *str, int sign, int counter)
{
	if (str_num_length(str) > LENGTHLONG && sign == -1)
		return (LONG_MIN);
	if (str_num_length(str) > LENGTHLONG && sign == 1)
		return (LONG_MAX);
	while (str_num_length(str) == LENGTHLONG && str[counter])
	{
		if (str[counter] > LONGMAX[counter] && sign == 1)
			return (LONG_MAX);
		if (str[counter] > LONGMIN[counter] && sign == -1)
			return (LONG_MIN);
		counter++;
	}
	return (0);
}

long	ft_atol(const char *str)
{
	int			sign;
	int			counter;
	char		*head;
	int			final;

	head = (char *)str;
	counter = 0;
	sign = 1;
	while (ft_isspace((int)*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = (-1);
		str++;
	}
	if ((final = ft_ok(str, sign, counter)) != 0)
		return (final);
	return (ft_atol_no_limit(head));
}
