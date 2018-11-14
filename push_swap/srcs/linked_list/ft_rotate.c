/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 23:00:49 by ajanmot           #+#    #+#             */
/*   Updated: 2017/12/01 23:01:31 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	rotate_a(t_pile **a)
{
	t_pile *save;
	t_pile *current;

	write(1, "ra\n", 3);
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

void	rotate_b(t_pile **b)
{
	t_pile *save;
	t_pile *current;

	write(1, "rb\n", 3);
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

void	rotate_both(t_pile **a, t_pile **b)
{
	rotate_a(a);
	rotate_b(b);
}
