/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 01:51:45 by ajanmot           #+#    #+#             */
/*   Updated: 2017/12/02 01:54:33 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

t_pile	*get_elem(t_pile *a, int value)
{
	while (a && a->value != value)
		a = a->next;
	if (!a)
		return (NULL);
	return (a);
}

int		get_max(t_pile *a)
{
	int i;
	int max;

	if (!a)
		return (-1);
	i = 1;
	max = a->value;
	a = a->next;
	while (a)
	{
		if (a->value > max)
			max = a->value;
		a = a->next;
		i++;
	}
	return (max);
}

int		get_second_max(t_pile *a)
{
	int max;
	int second_max;

	if (!a)
		return (-1);
	max = get_max(a);
	second_max = a->value;
	a = a->next;
	while (a)
	{
		if (a->value > second_max && a->value != max)
			second_max = a->value;
		a = a->next;
	}
	return (second_max);
}

int		get_pos(t_pile *a, t_pile *elem)
{
	int i;

	i = 1;
	while (a && a != elem)
	{
		a = a->next;
		i++;
	}
	if (!a)
		return (0);
	return (i);
}

t_pile	*get_last(t_pile *a)
{
	if (!a)
		return (NULL);
	while (a->next)
		a = a->next;
	return (a);
}
