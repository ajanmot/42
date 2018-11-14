/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoblech <hsoblech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 15:28:25 by hsoblech          #+#    #+#             */
/*   Updated: 2018/03/30 19:24:58 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_vm	init_vm(void)
{
	t_vm vm;

	vm.nbr_cycle = 1;
	vm.list_players = NULL;
	vm.list_process = NULL;
	vm.total_cycle = 1;
	vm.max_cycle = -1;
	vm.nbr_last_cycletodie_change = 1;
	vm.winner = NULL;
	ft_bzero(vm.memory_space, MEM_SIZE);
	vm.cycle_to_die = CYCLE_TO_DIE;
	vm.pid = 1;
	vm.param_v = 0;
	vm.param_c = 0;
	vm.param_d = 0;
	vm.param_ctd = 0;
	return (vm);
}

void	increment_pc(t_vm *vm, t_pc *pc, int times)
{
	int i;

	i = 0;
	while (i < times)
	{
		(*pc)++;
		if (*pc > vm->memory_space + MEM_SIZE - 1)
			*pc = vm->memory_space;
		i++;
	}
}

void	decrement_pc(t_vm *vm, t_pc *pc, int times)
{
	int i;

	i = 0;
	while (i < times)
	{
		(*pc)--;
		if (*pc < vm->memory_space)
			*pc = vm->memory_space + MEM_SIZE - 1;
		i++;
	}
}
