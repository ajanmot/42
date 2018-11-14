/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 20:37:02 by ajanmot           #+#    #+#             */
/*   Updated: 2017/11/17 09:03:16 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s)
{
	char *tail;
	char *new;
	char *head;

	if (!s)
		return (NULL);
	tail = (char *)s + ft_strlen(s) - 1;
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	if (!*s)
		s--;
	while ((*tail == ' ' || *tail == '\t' || *tail == '\n') && tail - s)
		tail--;
	if (!(new = ft_strnew((size_t)(tail - s + 1))))
		return (NULL);
	if ((head = new) && s == tail)
		return (new);
	while (s != tail)
	{
		*new = *s;
		s++;
		new++;
	}
	*new = *s;
	return (head);
}
