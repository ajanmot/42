/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 21:10:01 by ajanmot           #+#    #+#             */
/*   Updated: 2018/01/05 20:34:14 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/include.h"

void	ft_free_list(t_room *rooms)
{
	t_link *tmp;
	t_link *tmp_link;
	t_room *tmp_room;

	while (rooms)
	{
		if (rooms->links)
		{
			tmp = rooms->links;
			while (tmp)
			{
				tmp_link = tmp;
				tmp = tmp->next;
				free(tmp_link->from);
				free(tmp_link->to);
				free(tmp_link);
			}
		}
		tmp_room = rooms;
		rooms = rooms->next;
		free(tmp_room->name);
		free(tmp_room);
	}
}

void	ft_free_file(t_file *file)
{
	t_file *tmp;

	while (file)
	{
		tmp = file;
		file = file->next;
		free(tmp);
	}
}

int		ft_free_tab(char **tab, int status)
{
	char	*tmp;
	char	**head;

	head = tab;
	while (*tab && **tab)
	{
		tmp = *tab;
		tab++;
		free(tmp);
	}
	if (*head)
		free(head);
	return (status);
}

void	ft_free_start_end(char ***start_end)
{
	if (**start_end)
		free(**start_end);
	if ((*start_end)[1])
		free((*start_end)[1]);
	free(*start_end);
}

int		ft_free_line_and_quit(char *line, int ret)
{
	free(line);
	return (ret);
}
