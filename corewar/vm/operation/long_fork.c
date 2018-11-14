/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <pgerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 22:11:24 by pgerbaud          #+#    #+#             */
/*   Updated: 2018/03/30 20:17:48 by hsoblech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void		op_long_fork(t_vm *vm, t_process *process)
{
	int		value;
	t_pc	start;

	start = process->pc;
	increment_pc(vm, &(process->pc), 1);
	value = get_value_param(vm, process, start,
		get_param_w_type(vm, process, T_DIR, 2));
	add_process_fork(vm, get_adress_index(vm, process->pc, value, 0), process);
	if (vm->param_v)
	{
		if (value >= 0)
			verbose_op_fork(process, value,
				get_adress_index(vm, start, value, 1) - vm->memory_space, 1);
		else
			verbose_op_fork(process, value,
				(get_adress_index(vm, start, value, 1) - vm->memory_space)
				- MEM_SIZE, 1);
	}
}
