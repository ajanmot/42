/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 00:03:50 by ajanmot           #+#    #+#             */
/*   Updated: 2017/12/02 02:06:19 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int		moves_ra(int max_pos, int second_max, t_pile **a, t_pile **b)
{
	int times;

	times = max_pos - 1;
	if (second_max < max_pos)
	{
		times -= second_max;
		move(a, b, "rb", second_max - 1);
		move(a, b, "pa", 1);
	}
	return (times);
}

int		moves_rra(int max_pos, int second_max, t_pile **a, t_pile **b)
{
	int times;

	times = get_size(*b) - max_pos + 1;
	if (second_max > max_pos)
	{
		times -= (get_size(*b) - second_max) + 1;
		move(a, b, "rrb", get_size(*b) - second_max + 1);
		move(a, b, "pa", 1);
	}
	return (times);
}

int		move_and_pop(t_pile **a, t_pile **b, int max_pos, int size)
{
	char	*mvt;
	int		times;
	int		second_max;

	mvt = 0;
	times = 0;
	second_max = get_second_max(*b);
	if (max_pos <= size / 2 + 1 && second_max != max_pos)
	{
		times = moves_ra(max_pos, second_max, a, b);
		mvt = "rb";
	}
	else
	{
		mvt = "rrb";
		times = moves_rra(max_pos, second_max, a, b);
	}
	move(b, NULL, mvt, times);
	move(a, b, "pa", 1);
	if ((max_pos <= size / 2 + 1 && second_max < max_pos && second_max)
			|| (max_pos > size / 2 + 1 && second_max > max_pos))
		move(a, b, "sa", 1);
	return (times + 1);
}

int		select_sort(t_pile **a, t_pile **b)
{
	int moves;
	int size;

	moves = 0;
	while (*b)
	{
		size = get_pos(*b, get_last(*b));
		moves += calculate_and_move_to_top3(a, b, get_elem(*b, get_max(*b)));
		push_a(a, b);
		if (size - get_pos(*b, get_last(*b)) == 2)
			swap_a(a);
	}
	return (moves);
}
