/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushfront.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 10:44:36 by ajanmot           #+#    #+#             */
/*   Updated: 2017/11/17 10:46:41 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushfront(t_list **begin_list, void *data)
{
	t_list *new_elem;
	t_list *tmp;

	new_elem = ft_lstnew(data, sizeof(data));
	if (!begin_list || !(*begin_list))
	{
		*begin_list = new_elem;
		return ;
	}
	tmp = *begin_list;
	*begin_list = new_elem;
	(*begin_list)->next = tmp;
}
