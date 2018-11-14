/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 01:45:42 by ajanmot           #+#    #+#             */
/*   Updated: 2017/12/02 01:51:57 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

int	get_pos_max(t_pile *a)
{
	int save;
	int position;
	int i;

	if (!a)
		return (0);
	save = a->value;
	i = 1;
	position = 1;
	a = a->next;
	while (a)
	{
		if (save < a->value)
		{
			save = a->value;
			position = i;
		}
		i++;
		a = a->next;
	}
	return (position);
}

int	get_size(t_pile *a)
{
	int i;

	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}
