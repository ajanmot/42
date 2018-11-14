/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 20:01:47 by ajanmot           #+#    #+#             */
/*   Updated: 2018/03/30 20:21:09 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <limits.h>

int	ft_atoi(const char *str)
{
	int		signal;
	long	num;

	num = 0;
	signal = 1;
	while (*str <= 32 && *str > 0)
	{
		if (*str == '\e')
			return (0);
		++str;
	}
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			signal *= -1;
		++str;
	}
	while ((*str >= '0') && (*str <= '9'))
	{
		num *= 10;
		num += (*str - 48);
		++str;
	}
	num *= signal;
	return (num);
}
