/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_no_print.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 22:59:07 by ajanmot           #+#    #+#             */
/*   Updated: 2017/12/01 22:59:57 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	rotate_a_no_print(t_pile **a)
{
	t_pile *save;
	t_pile *current;

	if (a == NULL || *a == NULL || (*a)->next == NULL)
		return ;
	save = *a;
	(*a) = (*a)->next;
	current = (*a);
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = save;
	save->next = NULL;
}

void	rotate_b_no_print(t_pile **b)
{
	t_pile *save;
	t_pile *current;

	if (b == NULL || *b == NULL || (*b)->next == NULL)
		return ;
	save = *b;
	(*b) = (*b)->next;
	current = (*b);
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = save;
	save->next = NULL;
}

void	rotate_both_no_print(t_pile **a, t_pile **b)
{
	rotate_a_no_print(a);
	rotate_b_no_print(b);
}
