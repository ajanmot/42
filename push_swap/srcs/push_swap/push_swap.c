/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 23:06:58 by ajanmot           #+#    #+#             */
/*   Updated: 2017/12/13 07:57:38 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int		get_max_in_tab(int *min_pos, int pre_sort_nb)
{
	int max;
	int i;

	i = 1;
	max = min_pos[0];
	while (i < pre_sort_nb)
	{
		if (max < min_pos[i])
			max = min_pos[i];
		i++;
	}
	return (max);
}

int		move3(t_pile **a, t_pile **b, char *mvt, int times)
{
	int i;
	int second_max;

	i = 0;
	second_max = get_second_max(*b);
	while (i < times)
	{
		if (*b && (*b)->value == second_max)
		{
			push_a(a, b);
			if (!ft_strcmp(mvt, "rrb"))
				rotate_rev_b(b);
		}
		else if (elementary(a, b, mvt) == 0)
			exit(1);
		i++;
	}
	return (times);
}

int		calculate_and_move_to_top3(t_pile **a, t_pile **b, t_pile *to_top)
{
	char	*mvt;
	int		times;

	if (get_pos(*b, to_top) <= get_pos(*b, get_last(*b)) / 2 + 1)
	{
		times = get_pos(*b, to_top) - 1;
		mvt = "rb";
	}
	else
	{
		times = get_pos(*b, get_last(*b)) - get_pos(*b, to_top) + 1;
		mvt = "rrb";
	}
	return (move3(a, b, mvt, times));
}

void	free_pile(t_pile **a)
{
	t_pile *current;
	t_pile *tmp;

	current = *a;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
		tmp = NULL;
	}
	a = NULL;
}

int		main(int argc, char **argv)
{
	t_pile *a;
	t_pile *b;

	a = NULL;
	b = NULL;
	if (!arg_to_list(argc, argv, &a))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (ft_is_sort(a, b))
		return (0);
	if (get_pos(a, get_last(a)) == 3)
		size_of_3(&a);
	else if (get_pos(a, get_last(a)) < 6)
		less_than_6(&a, &b);
	else
		more_than_6(&a, &b);
	free_pile(&a);
	free_pile(&b);
	return (0);
}
