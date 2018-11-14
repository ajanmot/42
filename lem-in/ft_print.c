/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 21:13:40 by ajanmot           #+#    #+#             */
/*   Updated: 2018/01/05 19:12:01 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/include.h"

void	ft_print_rooms(t_room *rooms)
{
	while (rooms)
	{
		ft_printf("[ %s ] -> ", rooms->name);
		rooms = rooms->next;
	}
	ft_printf("[NULL]\n");
}

void	ft_print_rooms_all(t_room *rooms)
{
	t_link *tmp;

	while (rooms)
	{
		ft_printf("\nroom %s\n\n==>", rooms->name);
		if (rooms->links)
		{
			tmp = rooms->links;
			while (tmp)
			{
				ft_printf(" [%s] ->", tmp->to);
				tmp = tmp->next;
			}
		}
		ft_printf(" [ NULL ]\n");
		rooms = rooms->next;
	}
}

void	ft_print_file(t_file *f)
{
	while (f)
	{
		if (f->room->is_full == -1)
			ft_printf("[ %s : start] -> ", f->room->name);
		else if (f->room->is_full == -2)
			ft_printf("[ %s : end]", f->room->name);
		else
			ft_printf("[ %s : %d ] -> ", f->room->name, f->room->is_full);
		f = f->next;
	}
	ft_printf("[ NULL ]\n");
}
