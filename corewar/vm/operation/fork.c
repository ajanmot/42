/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <pgerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 22:11:24 by pgerbaud          #+#    #+#             */
/*   Updated: 2018/03/31 03:24:49 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void	op_fork(t_vm *vm, t_process *process)
{
	short int	value;
	t_pc		start;

	start = process->pc;
	increment_pc(vm, &(process->pc), 1);
	value = get_value_param_mod(vm, process, start,
		get_param_w_type(vm, process, T_DIR, 2));
	add_process_fork(vm, get_adress_index(vm, start, value, 1), process);
	if (vm->param_v)
	{
		if (value >= 0)
			verbose_op_fork(process, value, value + start - vm->memory_space,
0);
		else
			verbose_op_fork(process, value, value + start - vm->memory_space,
0);
	}
}

void	verbose_op_fork(t_process *process, short int jump,
	int current, int is_long)
{
	verbose_op_header(process);
	if (is_long)
		ft_printf("lfork %d (%d)\n", jump, current);
	else
		ft_printf("fork %d (%d)\n", jump, current);
}
