/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 20:36:28 by ajanmot           #+#    #+#             */
/*   Updated: 2018/03/30 19:45:06 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_count_words(char *str, char c)
{
	int i;
	int result;

	i = 0;
	result = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
		{
			result++;
			while (str[i] && !(str[i] == c))
				i++;
		}
	}
	return (result);
}

static int			ft_(char *str, char **result, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
		{
			result[j] = ft_strnew(ft_strclen(str + i, c));
			if (!result[j])
				return (-1);
			ft_strncpy(result[j], str + i, ft_strclen(str + i, c));
			j++;
			i += ft_strclen(str + i, c);
		}
	}
	return (j);
}

char				**ft_strsplit(char const *s, char c)
{
	char		**result;
	int			i;
	char		*str;

	if (!s)
		return (NULL);
	str = (char*)s;
	result = (char**)malloc(sizeof(char*) * (ft_count_words(str, c) + 1));
	if (!result)
		return (NULL);
	if ((i = ft_(str, result, c)) == -1)
		return (NULL);
	result[i] = 0;
	return (result);
}
