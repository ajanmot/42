/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 22:52:16 by ajanmot           #+#    #+#             */
/*   Updated: 2017/12/12 15:43:11 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int		ft_find_func(t_pile **a, t_pile **b, char *sign)
{
	if (!ft_strcmp(sign, "sa"))
		swap_a_no_print(a);
	else if (!ft_strcmp(sign, "sb"))
		swap_b_no_print(b);
	else if (!ft_strcmp(sign, "ss"))
		swap_both_no_print(a, b);
	else if (!ft_strcmp(sign, "pa"))
		push_a_no_print(a, b);
	else if (!ft_strcmp(sign, "pb"))
		push_b_no_print(a, b);
	else if (!ft_strcmp(sign, "ra"))
		rotate_a_no_print(a);
	else if (!ft_strcmp(sign, "rb"))
		rotate_b_no_print(b);
	else if (!ft_strcmp(sign, "rr"))
		rotate_both_no_print(a, b);
	else if (!ft_strcmp(sign, "rra"))
		rotate_rev_a_no_print(a);
	else if (!ft_strcmp(sign, "rrb"))
		rotate_rev_b_no_print(b);
	else if (!ft_strcmp(sign, "rrr"))
		rotate_reverse_both_no_print(a, b);
	else
		return (0);
	return (1);
}

int		do_op(t_pile **a, t_pile **b, char *buffer)
{
	if (!ft_find_func(a, b, buffer))
		return (-1);
	return (0);
}

int		ft_read_input(t_pile **a, t_pile **b)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		if (do_op(a, b, line) == -1)
			return (-1);
	}
	free(line);
	return (1);
}

int		main(int argc, char **argv)
{
	t_pile	*a;
	t_pile	*b;

	b = NULL;
	a = NULL;
	if (!arg_to_list(argc, argv, &a))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (ft_read_input(&a, &b) == -1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (!(ft_is_sort(a, b)))
		write(1, "KO!\n", 4);
	else
		write(1, "OK!\n", 4);
	ft_del(&a);
	ft_del(&b);
	return (0);
}
