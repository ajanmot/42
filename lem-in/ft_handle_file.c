/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 21:10:31 by ajanmot           #+#    #+#             */
/*   Updated: 2018/01/04 21:18:24 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/include.h"

t_file	*ft_new_file(t_room *to_link)
{
	t_file *new;

	if (!(new = (t_file *)malloc(sizeof(t_file))))
		return (NULL);
	new->room = to_link;
	new->next = NULL;
	return (new);
}

void	ft_file_pushback(t_file **file, t_room *to_link)
{
	t_file *new;
	t_file *current;

	if (!(new = ft_new_file(to_link)))
		ft_file_error(*file, to_link, 2);
	if (!file || !(*file))
	{
		*file = new;
		new->room->previous = NULL;
		return ;
	}
	current = *file;
	while (current->next)
		current = current->next;
	current->next = new;
}

int		ft_is_in_file(t_file *head, t_room *to_find)
{
	if (!head)
		return (0);
	while (head)
	{
		if (head->room == to_find)
			return (0);
		head = head->next;
	}
	return (1);
}

void	ft_queue(t_file **file, t_room **rooms)
{
	t_link *current;
	t_room *elem;

	current = (*file)->room->links;
	while (current)
	{
		elem = get_elem(rooms, current->to);
		if (elem->weight > (*file)->room->weight + 1 && !elem->used)
		{
			elem->weight = (*file)->room->weight + 1;
			if (elem->is_full != -1)
			{
				elem->previous = (*file)->room;
			}
			ft_file_pushback(file, elem);
		}
		current = current->next;
	}
}

int		ft_is_full(t_file *current)
{
	if (!current)
		return (1);
	while (current)
	{
		if (current->room->is_full > 0)
			return (1);
		current = current->next;
	}
	return (0);
}
