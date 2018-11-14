/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 10:51:30 by ajanmot           #+#    #+#             */
/*   Updated: 2017/11/17 10:54:58 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstsort(t_list **begin_list, int (*cmp)())
{
	int			changed;
	t_list		*head;

	changed = 1;
	if (*begin_list)
		while (changed)
		{
			changed = 0;
			head = *begin_list;
			while (head->next)
			{
				if ((*cmp)(head->content, head->next->content) > 0)
				{
					ft_ptrswap(&head->content, &head->next->content);
					changed = 1;
				}
				head = head->next;
			}
		}
}
