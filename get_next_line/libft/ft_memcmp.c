/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 20:22:09 by ajanmot           #+#    #+#             */
/*   Updated: 2017/11/11 20:22:16 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *s_s1;
	const unsigned char *s_s2;

	if (s1 == s2 || n == 0)
		return (0);
	s_s1 = (const unsigned char *)s1;
	s_s2 = (const unsigned char *)s2;
	while (n--)
	{
		if (*s_s1 != *s_s2)
			return (*s_s1 - *s_s2);
		if (n)
		{
			s_s1++;
			s_s2++;
		}
	}
	return (0);
}
