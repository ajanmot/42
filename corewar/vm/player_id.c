/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_id.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <pgerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 13:19:48 by pgerbaud          #+#    #+#             */
/*   Updated: 2018/03/30 19:53:38 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_player	*get_player_by_id_(t_list *list_players, int id)
{
	t_list		*current;
	t_player	*player;

	current = list_players;
	while (current)
	{
		player = ((t_player*)current->content);
		if (player->id == id)
			return (player);
		current = current->next;
	}
	return (NULL);
}

t_player	*get_player_by_id(t_vm *vm, int id)
{
	t_list		*current;
	t_player	*player;

	current = vm->list_players;
	while (current)
	{
		player = ((t_player*)current->content);
		if (player->id == id)
			return (player);
		current = current->next;
	}
	return (NULL);
}

int			generate_player_id(t_list *list_players)
{
	int			id;
	t_list		*current;
	t_player	*player;

	id = -1;
	current = list_players;
	while (current)
	{
		player = ((t_player*)current->content);
		if (player->id == id)
		{
			current = list_players;
			id--;
		}
		else
			current = current->next;
	}
	return (id);
}
