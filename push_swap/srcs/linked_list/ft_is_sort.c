/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 22:57:07 by ajanmot           #+#    #+#             */
/*   Updated: 2017/12/01 22:57:09 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

int	ft_is_sort(t_pile *pile, t_pile *b)
{
	t_pile *tmp;

	if (b)
		return (0);
	if (!pile)
		return (0);
	if (!pile->next)
		return (1);
	while (pile->next)
	{
		tmp = pile->next;
		if (pile->value > tmp->value)
			return (0);
		pile = pile->next;
	}
	return (1);
}
