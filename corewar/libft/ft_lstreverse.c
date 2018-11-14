/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <pgerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 10:44:36 by pgerbaud          #+#    #+#             */
/*   Updated: 2018/03/30 19:45:50 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstreverse(t_list **begin_list)
{
	t_list	*before;
	t_list	*current;
	t_list	*after;

	before = *begin_list;
	current = before->next;
	after = NULL;
	before->next = NULL;
	while (current)
	{
		after = current->next;
		current->next = before;
		before = current;
		current = after;
		if (after)
			after = after->next;
	}
	*begin_list = before;
}
