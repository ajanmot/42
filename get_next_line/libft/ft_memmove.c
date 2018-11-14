/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 20:22:42 by ajanmot           #+#    #+#             */
/*   Updated: 2017/11/11 20:23:08 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char *strsrc;
	char *strdst;

	strsrc = (char*)src;
	strdst = (char*)dst;
	if (strsrc < strdst)
	{
		strsrc = strsrc + n - 1;
		strdst = strdst + n - 1;
		while (n > 0)
		{
			*strdst-- = *strsrc--;
			n--;
		}
	}
	else
	{
		while (n > 0)
		{
			*strdst++ = *strsrc++;
			n--;
		}
	}
	return (dst);
}
