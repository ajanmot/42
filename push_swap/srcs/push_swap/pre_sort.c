/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 02:09:26 by ajanmot           #+#    #+#             */
/*   Updated: 2017/12/02 02:25:30 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	replace_in_tab(int to_replace, int max, int *min_pos, int pre_sort_nb)
{
	int i;

	i = 0;
	while (i < pre_sort_nb)
	{
		if (min_pos[i] == max)
		{
			min_pos[i] = to_replace;
			return ;
		}
		i++;
	}
}

void	set_min_tab(t_pile *a, int *min_pos, int pre_sort_nb)
{
	int i;
	int max;

	i = 0;
	while (i < pre_sort_nb && a)
	{
		min_pos[i] = a->value;
		i++;
		a = a->next;
	}
	while (a)
	{
		max = get_max_in_tab(min_pos, pre_sort_nb);
		while (a)
		{
			if (a->value < max)
			{
				replace_in_tab(a->value, max, min_pos, pre_sort_nb);
				a = a->next;
				break ;
			}
			a = a->next;
		}
	}
}

int		pre_sort(t_pile **a, t_pile **b, int pre_sort_nb)
{
	int	*min_pos;
	int	i;
	int	moves;

	moves = 0;
	i = 0;
	if (get_pos(*a, get_last(*a)) < pre_sort_nb)
		pre_sort_nb = get_pos(*a, get_last(*a));
	if (!(min_pos = malloc(sizeof(int) * pre_sort_nb)))
		return (-1);
	ft_memset(min_pos, 0, sizeof(min_pos));
	set_min_tab(*a, min_pos, pre_sort_nb);
	while (i < pre_sort_nb)
	{
		if (is_in_tab((*a)->value, min_pos, pre_sort_nb))
		{
			push_b(a, b);
			i++;
		}
		else
			rotate_a(a);
	}
	free(min_pos);
	return (moves);
}

int		is_in_tab(int n, int *min_pos, int pre_sort_nb)
{
	int i;

	i = 0;
	while (i < pre_sort_nb)
	{
		if (n == min_pos[i])
			return (1);
		i++;
	}
	return (0);
}
