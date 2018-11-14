/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_room.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 11:44:13 by ajanmot           #+#    #+#             */
/*   Updated: 2018/01/04 21:12:19 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/include.h"

t_room		*get_elem(t_room **head, char *to_find)
{
	t_room	*current;

	current = *head;
	while (current->next)
	{
		if (!ft_strcmp(current->name, to_find))
			return (current);
		current = current->next;
	}
	if (!ft_strcmp(current->name, to_find))
		return (current);
	return (NULL);
}

t_room		*ft_new_room(char *name)
{
	t_room *new;

	if (!(new = (t_room *)malloc(sizeof(t_room))))
		return (NULL);
	if (!*name)
		return (NULL);
	else
	{
		if (!(new->name = (char *)malloc(sizeof(char) * ft_strlen(name) + 1)))
		{
			free(new);
			return (NULL);
		}
		ft_strcpy(new->name, name);
	}
	new->links = NULL;
	new->used = 0;
	new->weight = INT_MAX;
	new->is_full = 0;
	new->next = NULL;
	new->previous = NULL;
	return (new);
}

void		ft_roompushback(t_room **begin_list, t_room *new)
{
	t_room *current;

	current = *begin_list;
	if (!begin_list || !(*begin_list))
	{
		*begin_list = new;
		return ;
	}
	while (current->next)
	{
		current = current->next;
	}
	current->next = new;
}

void		ft_add_room(char *line, t_room **rooms)
{
	char	**tab;
	t_room	*new;

	tab = NULL;
	if (!(tab = ft_strsplit(line, ' ')))
		lem_in_error(rooms, 4);
	if (!(new = ft_new_room(tab[0])))
		lem_in_error(rooms, 2);
	ft_roompushback(rooms, new);
	ft_free_tab(tab, 0);
}
