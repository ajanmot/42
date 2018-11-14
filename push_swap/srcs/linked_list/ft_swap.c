/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 23:03:03 by ajanmot           #+#    #+#             */
/*   Updated: 2017/12/01 23:04:09 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	swap_b(t_pile **pile)
{
	t_pile *save;
	t_pile *next_save;

	write(1, "sb\n", 3);
	if (!pile || !*pile)
		return ;
	save = *pile;
	if (((*pile)->next) == NULL)
		return ;
	*pile = (*pile)->next;
	next_save = (*pile)->next;
	(*pile)->next = save;
	save->next = next_save;
}

void	swap_a(t_pile **pile)
{
	t_pile *save;
	t_pile *next_save;

	write(1, "sa\n", 3);
	if (!pile || !*pile)
		return ;
	save = *pile;
	if (((*pile)->next) == NULL)
		return ;
	*pile = (*pile)->next;
	next_save = (*pile)->next;
	(*pile)->next = save;
	save->next = next_save;
}

void	swap_both(t_pile **a, t_pile **b)
{
	swap_a(a);
	swap_b(b);
}
