/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_way.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 15:53:43 by ajanmot           #+#    #+#             */
/*   Updated: 2018/01/05 19:10:26 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/include.h"

void	ft_backtrack_elem(t_room *elem, t_file **new)
{
	t_file *current;

	if (!elem)
		return ;
	ft_backtrack_elem(elem->previous, new);
	if (*new == NULL)
		*new = ft_new_file(elem);
	else
	{
		current = *new;
		while (current->next)
			current = current->next;
		current->next = ft_new_file(elem);
	}
}

t_file	*get_shorter_way(t_file *head, char **start_end)
{
	t_file *new;
	t_file *current;

	while (head)
	{
		if (!ft_strcmp(head->room->name, start_end[1]))
			break ;
		head = head->next;
	}
	if (!head)
		return (NULL);
	new = NULL;
	ft_backtrack_elem(head->room, &new);
	current = new;
	while (current)
	{
		if (current->room->is_full == 0)
			current->room->used = 1;
		current = current->next;
	}
	return (new);
}

void	ft_browse_way(t_file *current)
{
	if (current)
	{
		ft_browse_way(current->next);
		if (current->room->is_full > 0)
		{
			if (current->next->room->is_full >= 0)
			{
				ft_printf("L%d-%s ", current->room->is_full,
												current->next->room->name);
				current->next->room->is_full = current->room->is_full;
				current->room->is_full = 0;
			}
			else
			{
				ft_printf("L%d-%s ", current->room->is_full,
					current->next->room->name);
				current->room->is_full = 0;
				current->next->room->is_full--;
			}
		}
	}
}
