/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rv_nop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 23:01:40 by ajanmot           #+#    #+#             */
/*   Updated: 2017/12/01 23:02:09 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	rotate_rev_a_no_print(t_pile **a)
{
	t_pile *current;
	t_pile *save;

	if (a == NULL || *a == NULL || (*a)->next == NULL)
		return ;
	current = *a;
	save = *a;
	while (current->next->next)
		current = current->next;
	(*a) = current->next;
	current->next = NULL;
	(*a)->next = save;
}

void	rotate_rev_b_no_print(t_pile **b)
{
	t_pile *current;
	t_pile *save;

	if (b == NULL || *b == NULL || (*b)->next == NULL)
		return ;
	current = *b;
	save = *b;
	while (current->next->next)
		current = current->next;
	(*b) = current->next;
	current->next = NULL;
	(*b)->next = save;
}

void	rotate_reverse_both_no_print(t_pile **a, t_pile **b)
{
	rotate_rev_a_no_print(a);
	rotate_rev_b_no_print(b);
}
