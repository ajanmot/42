/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 21:13:15 by ajanmot           #+#    #+#             */
/*   Updated: 2018/01/04 21:13:31 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/include.h"

int		ft_unique_link(t_link *linker)
{
	t_link *tmp;

	while (linker)
	{
		tmp = linker->next;
		while (tmp)
		{
			if (!ft_strcmp(linker->to, tmp->to))
				return (0);
			tmp = tmp->next;
		}
		linker = linker->next;
	}
	return (1);
}

int		ft_check_doublons(t_room *rooms)
{
	t_room *tmp;

	while (rooms)
	{
		tmp = rooms->next;
		while (tmp)
		{
			if (!ft_strcmp(rooms->name, tmp->name))
				return (0);
			tmp = tmp->next;
		}
		if (!ft_unique_link(rooms->links))
			return (0);
		rooms = rooms->next;
	}
	return (1);
}
