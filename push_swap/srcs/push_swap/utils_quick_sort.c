/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_quick_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 02:27:13 by ajanmot           #+#    #+#             */
/*   Updated: 2017/12/02 02:28:41 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int		is_all_superior(t_pile *a, t_pile *elem)
{
	if (elem == a)
		return (1);
	while (a && a != elem && a->value > elem->value)
		a = a->next;
	if (a == elem)
		return (1);
	else
		return (0);
}

int		is_all_inferior(t_pile *a, t_pile *elem)
{
	if (elem == a)
		return (1);
	while (a && a != elem && a->value < elem->value)
		a = a->next;
	if (a == elem)
		return (1);
	else
		return (0);
}

t_pile	*get_previous(t_pile *a, t_pile *elem)
{
	if (elem == a)
		return (NULL);
	while (a->next && a->next != elem)
		a = a->next;
	if (!a->next)
		return (NULL);
	return (a);
}
