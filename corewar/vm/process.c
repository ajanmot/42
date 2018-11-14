/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <pgerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 13:22:30 by pgerbaud          #+#    #+#             */
/*   Updated: 2018/03/30 19:28:52 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_process	init_process(t_player *player, t_vm *vm)
{
	t_process	process;

	ft_bzero(process.reg, sizeof(t_register) * REG_NUMBER);
	(process.reg)[1] = player->id;
	process.pc = 0;
	process.carry = 0;
	process.pid = vm->pid;
	process.list_op = NULL;
	process.is_alive = 0;
	process.player = player;
	process.last_live = vm->total_cycle;
	process.wait = -1;
	process.wait_alive = 0;
	process.wait_fork = 0;
	return (process);
}

void		add_process(t_vm *vm, t_player *player)
{
	t_process process;

	process = init_process(player, vm);
	vm->pid++;
	ft_lstadd(&(vm->list_process), ft_lstnew(&process, sizeof(t_process)));
}

void		add_process_fork(t_vm *vm, t_pc pc, t_process *src)
{
	t_process process;

	process = init_process(src->player, vm);
	vm->pid++;
	process.carry = src->carry;
	ft_memcpy(process.reg, src->reg, sizeof(int) * REG_NUMBER);
	process.pc = pc;
	ft_lstadd(&(vm->list_process), ft_lstnew(&process, sizeof(t_process)));
}
