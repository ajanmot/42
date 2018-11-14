/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 20:36:28 by ajanmot           #+#    #+#             */
/*   Updated: 2018/01/05 18:37:37 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_words(char const *s, char c)
{
	int i;
	int words;

	i = 0;
	words = 0;
	if (s)
	{
		while (s[i])
		{
			while (s[i] && s[i] == c)
				i++;
			if (s[i] && s[i] != c)
				words++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (words);
}

static size_t	ft_word_length(const char *s, char c)
{
	int i;
	int len;

	i = 0;
	len = 0;
	if (!s)
		return (0);
	while (s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**fresh;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	if (!s || !(fresh = (char **)malloc(sizeof(char *) *
					(ft_count_words(s, c) + 1))))
		return (NULL);
	while (s[j] && i < ft_count_words(s, c))
	{
		if (!(fresh[i] = ft_strnew(ft_word_length(&s[j], c) + 1)))
			fresh[i] = (NULL);
		while (s[j] && s[j] == c)
			j++;
		while (s[j] && s[j] != c)
			fresh[i][k++] = s[j++];
		fresh[i][k] = '\0';
		k = 0;
		i++;
	}
	fresh[i] = 0;
	return (fresh);
}
