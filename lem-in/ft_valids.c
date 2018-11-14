/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valids.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 21:19:21 by ajanmot           #+#    #+#             */
/*   Updated: 2018/01/05 20:24:37 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/include.h"

int		ft_is_first_line_valid(void)
{
	char	*line;
	int		nb_fourmis;

	ft_buffer_get_next_line(&line, 0, 0);
	if ((nb_fourmis = ft_atoi(line)) <= 0)
		lem_in_error(NULL, 0);
	if (!ft_strisdigit(line))
		lem_in_error(NULL, 0);
	free(line);
	return (nb_fourmis);
}

int		ft_is_info_line_valid(char *line, t_room **rooms)
{
	char	**tab;
	char	**head;
	int		status;
	int		counter;

	counter = 0;
	if ((status = 1) && (!line || !*line))
		return (0);
	if (!(tab = ft_strsplit(line, ' ')))
		lem_in_error(rooms, 1);
	if (*tab && (head = tab))
		tab++;
	while (*tab)
	{
		if (!ft_strisdigit(*tab))
		{
			status = 0;
			break ;
		}
		counter++;
		tab++;
	}
	if (status)
		status = (counter == 2 ? 1 : 0);
	return (ft_free_tab(head, status));
}

char	*ft_is_comment(char *line, char ***start_end, t_room **rooms)
{
	if (!(*(line + 1)) || (ft_strcmp(line, "##start")
		&& ft_strcmp(line, "##end")))
	{
		free(line);
		ft_buffer_get_next_line(&line, 0, 0);
	}
	else if (*line == '#')
	{
		if (!ft_strcmp(line, "##start"))
			line = ft_alloc_line(line, start_end, 0, rooms);
		else if (!ft_strcmp(line, "##end"))
			line = ft_alloc_line(line, start_end, 1, rooms);
		if (!ft_is_info_line_valid(line, rooms))
		{
			free(line);
			return (NULL);
		}
		free(line);
		ft_buffer_get_next_line(&line, 0, 0);
	}
	return (*line ? line : NULL);
}

int		ft_is_linker(char *line, char ***tab, t_room **rooms)
{
	int		counter;
	int		res;

	counter = 0;
	while (line && *line == '#' && (res = 1))
	{
		free(line);
		res = ft_buffer_get_next_line(&line, 0, 0);
	}
	if (!res)
	{
		*tab = 0;
		return (1);
	}
	if (!line)
		return (res);
	if (!((*tab) = ft_strsplit(line, '-')))
		lem_in_error(rooms, 4);
	while ((*tab)[counter])
		counter++;
	if (counter != 2)
		return (ft_free_line_and_quit(line, 0));
	if (ft_strlen(line) == ft_strlen((*tab)[0]) + ft_strlen((*tab)[1]) + 1)
		return (ft_free_line_and_quit(line, 1));
	return (ft_free_line_and_quit(line, 0));
}

/*
**	Fonction permettant de savoir si toutes les informations sont presentes
*/

int		ft_is_ready(char ***start_end, t_room **rooms, char *line)
{
	char	**tab;

	if (*rooms && ft_is_linker(line, &tab, rooms))
		parse_links(rooms, &tab);
	if (!*rooms || !ft_check_doublons(*rooms) || !(*start_end)[0]
	|| !(*start_end)[1] || !ft_strcmp((*start_end)[0], (*start_end)[1]))
	{
		ft_free_start_end(start_end);
		lem_in_error(rooms, 1);
	}
	return (1);
}
