/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 20:01:47 by ajanmot           #+#    #+#             */
/*   Updated: 2017/11/19 17:34:37 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int	ft_atoi(const char *str)
{
	int		neg;
	int		nb_final;
	long	nb_long;
	int		tmp;

	neg = 1;
	nb_long = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t' ||
	*str == '\v' || *str == '\f' || *str == '\r'))
		str++;
	if ((*str == '+') || (*str == '-'))
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while ((*str >= '0') && (*str <= '9'))
	{
		nb_long *= 10;
		tmp = *str - 48;
		nb_long += tmp;
		str++;
	}
	nb_final = nb_long * neg;
	return (nb_final);
}
