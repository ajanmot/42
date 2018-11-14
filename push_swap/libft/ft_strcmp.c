/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 20:32:59 by ajanmot           #+#    #+#             */
/*   Updated: 2017/11/11 20:33:00 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
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
	return (a - b);
}
