/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_link.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 21:11:58 by ajanmot           #+#    #+#             */
/*   Updated: 2018/01/04 21:12:01 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/include.h"

void		ft_link_pushback(t_room *to_link, char **tab, int status)
{
	t_link	*current;
	t_link	*new;

	if (!(new = ft_new_link(tab, status)))
		lem_in_error(&to_link, 2);
	if (!(to_link->links))
	{
		to_link->links = new;
	}
	else
	{
		current = to_link->links;
		while (current->next)
			current = current->next;
		current->next = new;
	}
}

t_link		*ft_new_link(char **tab, int status)
{
	t_link	*new;

	if (!(new = (t_link *)malloc(sizeof(t_link))))
		return (NULL);
	new->next = NULL;
	if (status == 1)
	{
		new->from = ft_strdup(tab[1]);
		new->to = ft_strdup(tab[0]);
	}
	else
	{
		new->from = ft_strdup(tab[0]);
		new->to = ft_strdup(tab[1]);
	}
	return (new);
}
