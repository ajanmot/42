/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 08:07:37 by ajanmot           #+#    #+#             */
/*   Updated: 2018/01/05 20:26:28 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/include.h"
#include "includes/ft_error.h"

void	lem_in_error(t_room **rooms, int status)
{
	if (rooms)
		ft_free_list(*rooms);
	write(2, "ERROR : \n", 9);
	ft_putstr_fd(g_error_tab[status], 2);
	ft_buffer_get_next_line(NULL, 0, -1);
	exit(EXIT_FAILURE);
}

void	ft_file_error(t_file *file, t_room *rooms, int status)
{
	ft_free_file(file);
	ft_free_list(rooms);
	write(2, "ERROR : \n", 9);
	ft_putstr_fd(g_error_tab[status], 2);
	ft_buffer_get_next_line(NULL, 0, -1);
	exit(EXIT_FAILURE);
}

void	ft_dijkstra_error(t_ways *head, t_room *rooms,
	char **start_end, int status)
{
	ft_free_way(head);
	ft_free_list(rooms);
	ft_free_start_end(&start_end);
	write(2, "ERROR : \n", 9);
	ft_putstr_fd(g_error_tab[status], 2);
	ft_buffer_get_next_line(NULL, 0, -1);
	exit(EXIT_FAILURE);
}
