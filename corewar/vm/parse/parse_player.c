/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <pgerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 13:09:56 by pgerbaud          #+#    #+#             */
/*   Updated: 2018/03/31 02:20:07 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

t_pc		get_adress_index(t_vm *vm, t_pc pc, short index, int modulo)
{
	t_pc	adress;

	adress = pc;
	if (index < 0)
	{
		index = -index;
		if (modulo)
			index = index % IDX_MOD;
		decrement_pc(vm, &adress, index);
	}
	else
	{
		if (modulo)
			index = index % IDX_MOD;
		increment_pc(vm, &adress, index);
	}
	return (adress);
}

void		parse_player_name(t_player *player, int fd)
{
	int				i;
	unsigned char	buff[PROG_NAME_LENGTH + 1];

	i = 0;
	read(fd, &buff, PROG_NAME_LENGTH);
	buff[PROG_NAME_LENGTH] = 0;
	while (!buff[i] && i < PROG_NAME_LENGTH)
		i++;
	ft_strcpy(player->name, (char*)buff + i);
}

void		parse_player_comment(t_player *player, int fd)
{
	int				i;
	unsigned char	buff[COMMENT_LENGTH + 1];

	i = 0;
	read(fd, &buff, COMMENT_LENGTH);
	buff[COMMENT_LENGTH] = 0;
	ft_strcpy(player->comment, (char*)buff + i);
}

void		check_error_player(t_vm *vm, t_player *player, int n_player, int fd)
{
	int				start;
	unsigned int	i;
	unsigned char	byte;
	unsigned int	size_instruction;

	i = 0;
	size_instruction = (unsigned int)player->size;
	start = (MEM_SIZE / get_n_player(vm->list_players)) * n_player;
	if (size_instruction < 3)
		file_error(3, player->file, 0);
	lseek(fd, 16 + PROG_NAME_LENGTH + COMMENT_LENGTH, SEEK_SET);
	while (read(fd, &byte, 1) > 0 && start < MEM_SIZE)
	{
		vm->memory_space[start] = byte;
		start++;
		i++;
		if (i > CHAMP_MAX_SIZE)
			file_error(3, player->file, 0);
	}
	if (i < 3)
		file_error(4, player->file, 0);
}

int			get_n_player(t_list *list_players)
{
	t_list			*current;
	int				i;

	i = 0;
	current = list_players;
	while (current)
	{
		current = current->next;
		i++;
	}
	return (i);
}
