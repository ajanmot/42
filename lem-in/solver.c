/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 16:04:33 by ajanmot           #+#    #+#             */
/*   Updated: 2018/01/05 20:11:46 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/include.h"

int		ft_insert(t_ways *head, int nom_fourmis, int nb_fourmis)
{
	if (nom_fourmis <= nb_fourmis && head->ant_send < head->ant_to_send)
	{
		head->way->next->room->is_full = nom_fourmis;
		ft_printf("L%d-%s ", head->way->next->room->is_full,
										head->way->next->room->name);
		head->ant_send++;
		nom_fourmis++;
	}
	return (nom_fourmis);
}

void	ft_moove_ant(t_ways *head, int nb_fourmis)
{
	int		nom_fourmis;
	t_ways	*tmp;
	t_file	*last;

	nom_fourmis = 1;
	if (head->way->next->room->is_full < 0)
	{
		ft_direct_path(nom_fourmis, nb_fourmis, head->way);
		return ;
	}
	tmp = head;
	last = head->way;
	while (last->next)
		last = last->next;
	while (last->room->is_full != (nb_fourmis + 2) * -1)
	{
		while (head)
		{
			ft_browse_way(head->way);
			nom_fourmis = ft_insert(head, nom_fourmis, nb_fourmis);
			head = head->next;
		}
		ft_printf("\n");
		head = tmp;
	}
}

/*
** Fonction permettant d'optimiser le nombre de fourmis a envoyer dans chaque
** chemins trouvé.
*/

void	ft_optimise(t_ways *head, int nb_fourmis)
{
	float	max_size;
	t_ways	*current;
	float	somme_coef;
	float	tmp;

	max_size = ft_get_max_size(head);
	current = head;
	somme_coef = 0;
	while (current)
	{
		current->coefficient = (float)(max_size / ft_get_size(current->way));
		somme_coef += current->coefficient;
		current = current->next;
	}
	current = head;
	while (current)
	{
		tmp = nb_fourmis / somme_coef * current->coefficient + 0.5;
		current->ant_to_send = tmp;
		current = current->next;
	}
}

void	ft_solver(t_room **rooms, char **start_end, int nb_fourmis)
{
	t_file	*found;
	t_file	*current;
	t_ways	*head;

	head = NULL;
	while (1)
	{
		found = ft_handle_dijkstra(rooms, start_end);
		if (!(current = get_shorter_way(found, start_end)))
		{
			ft_free_file(found);
			break ;
		}
		ft_ways_push_back(&head, current);
		ft_reset_rooms(found);
		ft_free_file(found);
	}
	if (head == NULL)
		ft_dijkstra_error(head, *rooms, start_end, 3);
	ft_buffer_get_next_line(NULL, 0, 1);
	ft_optimise(head, nb_fourmis);
	ft_moove_ant(head, nb_fourmis);
	ft_free_way(head);
}
