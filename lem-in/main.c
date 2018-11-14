/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 14:10:22 by ajanmot           #+#    #+#             */
/*   Updated: 2018/01/05 20:27:34 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/include.h"

int	main(void)
{
	t_room	*room;
	char	**start_end;
	int		nb_fourmis;

	room = NULL;
	if (!(start_end = (char **)ft_memalloc(sizeof(char *) * 2)))
		lem_in_error(&room, 2);
	nb_fourmis = parser(&room, &start_end);
	ft_solver(&room, start_end, nb_fourmis);
	ft_free_start_end(&start_end);
	ft_free_list(room);
}
