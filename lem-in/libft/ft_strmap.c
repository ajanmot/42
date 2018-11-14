/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 20:34:30 by ajanmot           #+#    #+#             */
/*   Updated: 2017/11/11 21:18:48 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*result;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	result = ft_strnew(ft_strlen(s));
	if (!result)
		return (NULL);
	while (s[i])
	{
		result[i] = (*f)(s[i]);
		i++;
	}
	return (result);
}
