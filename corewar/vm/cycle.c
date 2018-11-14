/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <pgerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 13:28:18 by pgerbaud          #+#    #+#             */
/*   Updated: 2018/03/31 02:13:44 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	exec_op(t_vm *vm, t_process *process, unsigned char *id)
{
	void			(*op_def)(t_vm*, t_process*);

	*id = (unsigned char)*(process->pc);
	if (*id && *id <= 16)
	{
		op_def = g_get_op_function(*id);
		op_def(vm, process);
	}
	process->wait = -1;
	process->wait_alive = 2;
}

void	upgrade_op_list(t_vm *vm, t_process *process)
{
	unsigned char	id;

	if (process->wait == -1)
	{
		id = (unsigned char)*(process->pc);
		if (id && id <= 16)
		{
			process->wait = get_cycle_op(id) - 1;
			if (id == 1)
				process->wait_alive = 1;
			if (id == 12)
				process->wait_fork = 12;
		}
		else
			increment_pc(vm, &(process->pc), 1);
	}
	else if (!(process->wait))
	{
		exec_op(vm, process, &id);
	}
	if (process->wait > 0)
		(process->wait)--;
}

int		alive_count(t_vm *vm)
{
	t_list		*current;
	int			live;

	live = 0;
	current = vm->list_process;
	while (current)
	{
		live += ((t_process *)current->content)->is_alive;
		current = current->next;
	}
	return (live);
}

void	exec_cycle(t_vm *vm)
{
	t_list		*current;

	while (vm->list_players)
	{
		current = vm->list_process;
		if (vm->param_c)
			ft_printf("It is now cycle %d\n", vm->total_cycle);
		if (vm->max_cycle == 0)
			end_dump(vm);
		if (vm->cycle_to_die <= 0)
			end_game(vm);
		if (vm->cycle_to_die <= 0 || vm->nbr_cycle == vm->cycle_to_die)
			check_cycletodie(vm, current);
		current = vm->list_process;
		while (current)
		{
			if ((t_process *)current->content)
				upgrade_op_list(vm, (t_process *)current->content);
			current = current->next;
		}
		vm->max_cycle--;
		vm->nbr_cycle++;
		vm->total_cycle++;
	}
}
