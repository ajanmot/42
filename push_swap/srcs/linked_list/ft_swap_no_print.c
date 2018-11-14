/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_no_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 23:02:14 by ajanmot           #+#    #+#             */
/*   Updated: 2017/12/01 23:02:57 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	swap_b_no_print(t_pile **pile)
{
	t_pile *save;
	t_pile *next_save;

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

void	swap_a_no_print(t_pile **pile)
{
	t_pile *save;
	t_pile *next_save;

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

void	swap_both_no_print(t_pile **a, t_pile **b)
{
	swap_a_no_print(a);
	swap_b_no_print(b);
}
