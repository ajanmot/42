/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 19:14:34 by tkeynes           #+#    #+#             */
/*   Updated: 2018/04/12 10:51:56 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

int				is_spaces(char *str)
{
	while (*str)
	{
		if (*str != ' ' && *str != '\t' && *str != '\v' && *str != '\f' &&
*str != '\r')
			return (0);
		str++;
	}
	return (1);
}

int				ft_free(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = 0;
	}
	return (1);
}
