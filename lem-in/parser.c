/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 08:43:45 by ajanmot           #+#    #+#             */
/*   Updated: 2018/01/05 20:35:35 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/include.h"

char	*ft_alloc_line(char *line, char ***start_end, int status
															, t_room **rooms)
{
	char	*tmp;

	while (*line == '#')
	{
		free(line);
		ft_buffer_get_next_line(&line, 0, 0);
	}
	if (!*line)
	{
		free(line);
		return (NULL);
	}
	if ((*start_end)[status])
		return (NULL);
	if (!(tmp = ft_strchr(line, ' ')))
		return (NULL);
	(*start_end)[status] = ft_strnew(tmp - line);
	(*start_end)[status] = ft_strncpy((*start_end)[status], line, tmp - line);
	ft_add_room(line, rooms);
	return (line);
}

int		parse_links(t_room **rooms, char ***tab)
{
	t_room		*link_2;
	t_room		*link_1;
	char		*line;

	if (!rooms || !(link_1 = get_elem(rooms, (*tab)[0]))
									|| !(link_2 = get_elem(rooms, (*tab)[1])))
		return (0);
	ft_link_pushback(link_1, *tab, 0);
	ft_link_pushback(link_2, *tab, 1);
	ft_free_tab(*tab, 0);
	while (ft_buffer_get_next_line(&line, 0, 0))
	{
		if (!ft_is_linker(line, tab, rooms))
			return (ft_free_tab(*tab, 0));
		if (!*tab)
			return (1);
		if (!rooms || !(link_1 = get_elem(rooms, (*tab)[0]))
									|| !(link_2 = get_elem(rooms, (*tab)[1])))
			return (ft_free_tab(*tab, 0));
		ft_link_pushback(link_1, *tab, 0);
		ft_link_pushback(link_2, *tab, 1);
		ft_free_tab(*tab, 0);
	}
	free(line);
	return (1);
}

int		parse_rooms(t_room **rooms, char ***start_end)
{
	char *line;

	while (ft_buffer_get_next_line(&line, 0, 0))
	{
		while (*line == '#')
			if (!(line = ft_is_comment(line, start_end, rooms)))
				return (ft_is_ready(start_end, rooms, line));
		if (!ft_is_info_line_valid(line, rooms))
			return (ft_is_ready(start_end, rooms, line));
		ft_add_room(line, rooms);
		free(line);
	}
	return (ft_is_ready(start_end, rooms, line));
}

int		parser(t_room **rooms, char ***start_end)
{
	int		nb_fourmis;
	t_room	*elem;

	if (!(nb_fourmis = ft_is_first_line_valid()))
		lem_in_error(rooms, 0);
	if (!parse_rooms(rooms, start_end))
		lem_in_error(rooms, 1);
	elem = get_elem(rooms, **start_end);
	elem->is_full = -1;
	elem = get_elem(rooms, (*start_end)[1]);
	elem->is_full = -2;
	return (nb_fourmis);
}
