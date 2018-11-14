/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 20:20:21 by ajanmot           #+#    #+#             */
/*   Updated: 2017/11/12 16:08:44 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char *s_dest;
	unsigned char *s_src;

	s_src = (unsigned char *)src;
	s_dest = (unsigned char *)dest;
	while (n && *s_src != (unsigned char)c)
	{
		*s_dest++ = *s_src++;
		n--;
	}
	if (n)
	{
		*s_dest++ = *s_src++;
		return ((void *)s_dest);
	}
	else
		return (NULL);
}
