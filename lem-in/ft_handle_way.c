/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_way.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 16:00:22 by ajanmot           #+#    #+#             */
/*   Updated: 2018/01/04 21:13:11 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/include.h"

t_ways	*ft_new_ways(t_file *to_link)
{
	t_ways *new;

	if (!(new = (t_ways *)malloc(sizeof(t_ways))))
		return (NULL);
	new->way = to_link;
	new->next = NULL;
	new->ant_send = 0;
	return (new);
}

void	ft_ways_push_back(t_ways **head, t_file *to_link)
{
	t_ways *new;
	t_ways *current;

	if (!(new = ft_new_ways(to_link)))
		lem_in_error(NULL, 2);
	if (!head || !(*head))
	{
		*head = new;
		return ;
	}
	current = *head;
	while (current->next)
		current = current->next;
	current->next = new;
}

int		ft_get_size(t_file *elem)
{
	int i;

	i = 0;
	while (elem)
	{
		i++;
		elem = elem->next;
	}
	return (i);
}

int		ft_get_max_size(t_ways *head)
{
	int max;
	int res;

	max = 0;
	while (head)
	{
		if ((res = ft_get_size(head->way)) > max)
			max = res;
		head = head->next;
	}
	return (max);
}

void	ft_free_way(t_ways *head)
{
	t_ways *tmp;

	while (head)
	{
		ft_free_file(head->way);
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
