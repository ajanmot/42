/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsanitize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 20:56:58 by ajanmot           #+#    #+#             */
/*   Updated: 2018/03/30 19:14:25 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

int			ft_remove_tabs_and_comments(char *str, int i, int res, int in)
{
	while (str[i])
	{
		if (str[i] == '"')
			in = !in;
		if (str[i] == COMMENT_CHAR && !in)
		{
			str[i] = '\0';
			res = ft_strlen(&(str[i + 1]));
			break ;
		}
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (str[i] == '"')
			break ;
		if (str[i] == 9)
			str[i] = ' ';
		i++;
	}
	return (res);
}

void		replace_space_beetween_coma(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '"')
			break ;
		if (str[i] == SEPARATOR_CHAR && *(str + 1) && str[i + 1] == ' ')
		{
			str[i + 1] = '\0';
			if (str[i + 2])
				ft_strcat(str, &(str[i + 2]));
			i = -1;
		}
		else if (str[i] == ' ' && *(str + 1) && str[i + 1] == SEPARATOR_CHAR)
		{
			str[i] = SEPARATOR_CHAR;
			str[i + 1] = '\0';
			if (str[i + 2])
				ft_strcat(str, &(str[i + 2]));
			i = -1;
		}
		i++;
	}
}

char		*ft_strsanitize(char *str, t_file *file, int size)
{
	int		i;
	char	*tmp;

	i = 0;
	size = ft_strlen(str) - ft_remove_tabs_and_comments(str, 0, 0, 0);
	while (str[i])
	{
		if (str[i] == '"')
			break ;
		if (str[i] == ' ' && str[i + 1] && str[i + 1] == ' ')
		{
			str[i] = ' ';
			str[i + 1] = '\0';
			size--;
			ft_strcat(str, &(str[i + 2]));
			i = -1;
		}
		i++;
	}
	replace_space_beetween_coma(str);
	tmp = str;
	if (str[ft_strlen(str) - 1] == ',' || !(str = ft_strtrim(str)))
		ft_error_asm("Erreur sanitizing\n", file, tmp);
	ft_free(tmp);
	return (str);
}
