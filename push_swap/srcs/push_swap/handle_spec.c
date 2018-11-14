/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_spec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 02:23:37 by ajanmot           #+#    #+#             */
/*   Updated: 2017/12/02 19:45:25 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	more_than_6(t_pile **a, t_pile **b)
{
	int pre_value;
	int moves;

	pre_value = get_size(*a) * 0.0522 + 17.312;
	moves = 0;
	while (*a)
		moves += pre_sort(a, b, pre_value);
	moves += select_sort(a, b);
}

void	less_than_6(t_pile **a, t_pile **b)
{
	pre_sort(a, b, 4);
	select_sort(a, b);
}

void	size_of_3(t_pile **a)
{
	t_pile *current;

	current = *a;
	if (current->next->value < current->value)
	{
		swap_a(a);
		current = *a;
	}
	if (current->value < current->next->value && current->next->value
		> current->next->next->value)
	{
		rotate_rev_a(a);
		current = *a;
	}
	if (current->next->value < current->value)
		swap_a(a);
}
