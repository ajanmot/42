/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 21:14:03 by ajanmot           #+#    #+#             */
/*   Updated: 2018/01/05 19:33:24 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/include.h"

char			*ft_bfrjoin(char *s1, char *s2)
{
	char *fresh;

	if (!s1)
	{
		fresh = ft_strnew(ft_strlen(s2) + 2);
		ft_strcat(fresh, s2);
		fresh[ft_strlen(s2)] = '\n';
		fresh[ft_strlen(s2) + 1] = '\0';
		return (fresh);
	}
	fresh = ft_strnew(ft_strlen(s2) + ft_strlen(s1) + 2);
	ft_strcat(fresh, s1);
	ft_strcat(fresh, s2);
	fresh[ft_strlen(s2) + ft_strlen(s1)] = '\n';
	fresh[ft_strlen(s2) + ft_strlen(s1) + 1] = '\0';
	free(s1);
	return (fresh);
}

int				ft_buffer_get_next_line(char **line, int fd, int status)
{
	static char *buffer;
	int			res;

	if (status == 1)
	{
		ft_putstr(buffer);
		free(buffer);
		return (0);
	}
	if (status == -1)
	{
		free(buffer);
		return (0);
	}
	res = get_next_line(fd, line);
	buffer = ft_bfrjoin(buffer, *line);
	return (res);
}

int				ft_strisdigit(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
