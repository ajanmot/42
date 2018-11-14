/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 20:35:15 by ajanmot           #+#    #+#             */
/*   Updated: 2017/11/12 17:47:41 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char a;
	unsigned char b;

	if (!n)
		return (0);
	while ((*s1 == *s2) && --n)
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
