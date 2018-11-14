/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoblech <hsoblech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 14:24:14 by hsoblech          #+#    #+#             */
/*   Updated: 2018/03/31 02:13:19 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		get_procces_by_pc(t_vm *vm, t_pc pc)
{
	t_list		*current;
	t_process	*process;

	current = vm->list_process;
	while (current)
	{
		process = (t_process*)(current->content);
		if (process->pc == pc)
			return (process->pid);
		current = current->next;
	}
	return (-1);
}

void	dump_memory(t_vm *vm)
{
	int		i;
	int		pid;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (i == 0)
			ft_printf("0x");
		if (!(i % 64))
			ft_printf("%#.4x : ", i);
		pid = get_procces_by_pc(vm, (&(vm->memory_space)[i]));
		ft_printf("%.2x ", (vm->memory_space)[i]);
		i++;
		if (!(i % 64))
			ft_printf("\n");
	}
}

void	dump_players(t_list *list_player)
{
	t_list		*current;
	t_player	*player;

	current = list_player;
	while (current)
	{
		player = ((t_player*)current->content);
		dump_player(player);
		current = current->next;
	}
}

void	dump_player(t_player *player)
{
	ft_printf(C_BLUE"==== Player : %d ====\n"C_NONE, player->id);
	ft_printf("File : %s\n", player->file);
	ft_printf("Name : %s\n", player->name);
	ft_printf("Comment : %s\n", player->comment);
	ft_printf("Size : %d bytes\n", player->size);
}
