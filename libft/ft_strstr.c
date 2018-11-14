/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 20:36:33 by ajanmot           #+#    #+#             */
/*   Updated: 2017/11/11 20:36:49 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static int		ft_cmp(const char *s1, const char *s2, unsigned int n)
{
	int i;

	i = 0;
	if (!n)
		return (0);
	while (n)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
		n--;
	}
	return (1);
}

char			*ft_strstr(const char *str, const char *to_find)
{
	int f_len;
	int s_len;
	int current;

	f_len = ft_strlen(to_find);
	s_len = ft_strlen(str);
	current = 0;
	if (!*to_find)
		return ((char *)str);
	while (current < s_len - f_len + 1)
	{
		if (!str[current])
			return (0);
		if (ft_cmp(str + current, to_find, f_len))
		{
			return ((char *)str + current);
		}
		current++;
	}
	return (0);
}
