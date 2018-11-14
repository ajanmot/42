/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 20:35:34 by ajanmot           #+#    #+#             */
/*   Updated: 2017/11/11 20:35:35 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t j;
	size_t start;

	i = 0;
	j = 0;
	if (!(ft_strcmp(little, "")))
		return ((char *)big);
	while (big[i] && i < len)
	{
		start = i;
		j = 0;
		while (big[i] == little[j] && i < len)
		{
			i++;
			j++;
			if (little[j] == '\0' && little[j - 1] == big[i - 1])
				return (char *)(&big[start]);
		}
		i = start;
		i++;
	}
	return (0);
}
