/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dijkstra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 16:02:30 by ajanmot           #+#    #+#             */
/*   Updated: 2018/01/05 19:10:26 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/include.h"

void	ft_direct_path(int nom_fourmis, int nb_fourmis, t_file *current)
{
	while (nom_fourmis < nb_fourmis)
	{
		ft_printf("L%d-%s \n", nom_fourmis, current->next->room->name);
		nom_fourmis++;
	}
}

t_file	*ft_handle_dijkstra(t_room **rooms, char **start_end)
{
	t_file *head;
	t_file *current;

	head = NULL;
	ft_file_pushback(&head, get_elem(rooms, *start_end));
	ft_queue(&head, rooms);
	current = head;
	current = current->next;
	while (current)
	{
		ft_queue(&current, rooms);
		current = current->next;
	}
	return (head);
}

void	ft_reset_rooms(t_file *head)
{
	while (head)
	{
		if (head->room->is_full != -1 && !head->room->used)
		{
			head->room->weight = INT_MAX;
			head->room->previous = NULL;
		}
		head = head->next;
	}
}
