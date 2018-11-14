/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 09:41:45 by ajanmot           #+#    #+#             */
/*   Updated: 2017/11/17 10:30:11 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushback(t_list **begin_list, void *data)
{
	t_list *current;
	t_list *new;

	new = ft_lstnew(data, sizeof(data));
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
