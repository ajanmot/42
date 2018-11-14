/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 22:57:18 by ajanmot           #+#    #+#             */
/*   Updated: 2017/12/12 14:57:12 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	ft_list_push_back(t_pile **begin_list, int data)
{
	t_pile *current;
	t_pile *new;

	new = ft_create_elem(data);
	current = *begin_list;
	if (!begin_list || !(*begin_list))
	{
		*begin_list = new;
		return ;
	}
	while (current->next)
	{
		current = current->next;
	}
	current->next = new;
}

void	ft_list_push_params(t_pile **list, char **av)
{
	while (*av)
	{
		ft_list_push_back(list, ft_atoi(*av));
		av++;
	}
}
