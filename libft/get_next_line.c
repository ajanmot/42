/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 21:47:59 by ajanmot           #+#    #+#             */
/*   Updated: 2018/01/06 05:09:29 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_chrcpy(char *str)
{
	if (ft_strchr(str, '\n'))
		return (ft_strcpy(str, ft_strchr(str, '\n') + 1));
	if (ft_strlen(str))
	{
		ft_strcpy(str, ft_strchr(str, '\0'));
		return (str);
	}
	return (NULL);
}

char		*ft_read_buffer(char *buffer, char *tmp, int fd, int *res)
{
	char		*ptr;

	while (!ft_strchr(buffer, '\n') && (*res = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		tmp[*res] = '\0';
		ptr = buffer;
		buffer = ft_strjoin(buffer, tmp);
		free(ptr);
	}
	return (buffer);
}

int			get_next_line(int const fd, char **line, int status)
{
	char		*tmp;
	static char	*buffer = NULL;
	int			res;

	if (status)
	{
		free(buffer);
		return (0);
	}
	res = 0;
	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	if (!buffer && !(buffer = ft_strnew(0)))
		return (-1);
	if (!(tmp = ft_strnew(BUFF_SIZE)))
		return (-1);
	buffer = ft_read_buffer(buffer, tmp, fd, &res);
	if (res == -1 || !(*line = ft_strsub(buffer, 0, ft_strclen(buffer, '\n'))))
		return (-1);
	free(tmp);
	if (!ft_chrcpy(buffer))
	{
		free(buffer);
		return (0);
	}
	return (1);
}
