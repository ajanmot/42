/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 23:33:23 by ajanmot           #+#    #+#             */
/*   Updated: 2017/12/02 19:45:27 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int		elementary(t_pile **a, t_pile **b, char *sign)
{
	if (!ft_strcmp(sign, "sa"))
		swap_a(a);
	else if (!ft_strcmp(sign, "sb"))
		swap_b(b);
	else if (!ft_strcmp(sign, "ss"))
		swap_both(a, b);
	else if (!ft_strcmp(sign, "pa"))
		push_a(a, b);
	else if (!ft_strcmp(sign, "pb"))
		push_b(a, b);
	else if (!ft_strcmp(sign, "ra"))
		rotate_a(a);
	else if (!ft_strcmp(sign, "rb"))
		rotate_b(b);
	else if (!ft_strcmp(sign, "rr"))
		rotate_both(a, b);
	else if (!ft_strcmp(sign, "rra"))
		rotate_rev_a(a);
	else if (!ft_strcmp(sign, "rrb"))
		rotate_rev_b(b);
	else if (!ft_strcmp(sign, "rrr"))
		rotate_reverse_both(a, b);
	else
		return (0);
	return (1);
}

int		move(t_pile **a, t_pile **b, char *mvt, int times)
{
	int i;

	i = 0;
	while (i < times)
	{
		elementary(a, b, mvt);
		i++;
	}
	return (times);
}

int		calculate_and_move_to_top(t_pile **a, t_pile *to_top)
{
	char	*mvt;
	int		times;

	if (get_pos(*a, to_top) <= get_pos(*a, get_last(*a)) / 2 + 1)
	{
		times = get_pos(*a, to_top) - 1;
		mvt = "ra";
	}
	else
	{
		times = get_pos(*a, get_last(*a)) - get_pos(*a, to_top) + 1;
		mvt = "rra";
	}
	return (move(a, NULL, mvt, times));
}

void	quick_sort_all_superior(t_pile **a, t_pile **b, t_pile *pivot,
	t_pile *save)
{
	if (is_all_superior(*a, pivot))
	{
		save = *a;
		calculate_and_move_to_top(a, pivot);
		push_b(a, b);
		calculate_and_move_to_top(a, save);
	}
}

void	recursiv_push_swap(t_pile **a, t_pile **b, t_pile *current,
	t_pile *pivot)
{
	t_pile *save;

	if (pivot == NULL)
		return ;
	if (pivot == *a && !is_all_inferior(*a, get_last(*a)))
		return (recursiv_push_swap(a, b, *a, get_last(*a)));
	if (current->next == pivot && current->value > pivot->value)
		return (swap_a(a));
	if (is_all_inferior(*a, pivot))
		return (recursiv_push_swap(a, b, *a, get_previous(*a, pivot)));
	while (current != pivot && !is_all_superior(*a, pivot))
	{
		if (current->value < pivot->value)
		{
			save = current->next;
			calculate_and_move_to_top(a, current);
			push_b(a, b);
			current = save;
		}
		else
			current = current->next;
	}
	quick_sort_all_superior(a, b, pivot, save);
	move(a, b, "pa", get_pos(*b, get_last(*b)));
	return (recursiv_push_swap(a, b, *a, get_previous(*a, pivot)));
}
