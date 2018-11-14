/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 20:35:39 by ajanmot           #+#    #+#             */
/*   Updated: 2017/11/11 20:36:20 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_char_count(const char *s, char c)
{
	int counter;

	counter = 0;
	while (*s)
	{
		if (*s == c)
			counter++;
		s++;
	}
	return (counter);
}
