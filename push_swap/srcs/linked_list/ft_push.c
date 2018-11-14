/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 22:58:16 by ajanmot           #+#    #+#             */
/*   Updated: 2017/12/01 22:58:56 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	push_b(t_pile **a, t_pile **b)
{
	t_pile *save;

	write(1, "pb\n", 3);
	if (a == NULL || *a == NULL)
		return ;
	save = (*a);
	(*a) = (*a)->next;
	save->next = (*b);
	(*b) = save;
}

void	push_a(t_pile **a, t_pile **b)
{
	t_pile *save;

	write(1, "pa\n", 3);
	if (b == NULL || *b == NULL)
		return ;
	save = (*b);
	(*b) = (*b)->next;
	save->next = (*a);
	(*a) = save;
}
