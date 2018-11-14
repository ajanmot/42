/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_no_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 22:57:33 by ajanmot           #+#    #+#             */
/*   Updated: 2017/12/01 22:58:12 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	push_b_no_print(t_pile **a, t_pile **b)
{
	t_pile *save;

	if (a == NULL || *a == NULL)
		return ;
	save = (*a);
	(*a) = (*a)->next;
	save->next = (*b);
	(*b) = save;
}

void	push_a_no_print(t_pile **a, t_pile **b)
{
	t_pile *save;

	if (b == NULL || *b == NULL)
		return ;
	save = (*b);
	(*b) = (*b)->next;
	save->next = (*a);
	(*a) = save;
}
