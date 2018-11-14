/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 20:34:44 by ajanmot           #+#    #+#             */
/*   Updated: 2017/11/11 21:21:54 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlen(const char *str)
{
	int		len;
	char	*tmp_str;

	len = 0;
	tmp_str = (char *)str;
	while (*str)
	{
		len++;
		str++;
	}
	str = tmp_str;
	return (len);
}
