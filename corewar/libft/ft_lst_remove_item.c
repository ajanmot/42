/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_remove_item.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <tkeynes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 13:28:18 by tkeynes           #+#    #+#             */
/*   Updated: 2018/03/30 21:58:12 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_remove_item(t_list **list, t_list *item,
		void (*del)(void*, size_t))
{
	t_list	*prev;
	t_list	*current;

	if ((*list) == item)
	{
		(*list) = (*list)->next;
		ft_lstdelone(&item, del);
		return ;
	}
	current = (*list)->next;
	prev = (*list);
	while (current)
	{
		if (current == item)
		{
			prev->next = current->next;
			ft_lstdelone(&item, del);
			return ;
		}
		prev = current;
		current = current->next;
	}
	ft_lstdelone(&item, del);
}
