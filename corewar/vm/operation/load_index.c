/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <pgerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 22:11:24 by pgerbaud          #+#    #+#             */
/*   Updated: 2018/03/31 02:16:00 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

static void	op_load_exec(t_vm *vm, t_process *process,
	unsigned char bin_code, t_pc start)
{
	t_param			param1;
	t_param			param2;
	t_param			param3;
	int				value[3];

	param1 = get_param(vm, process, &bin_code, 2);
	param2 = get_param(vm, process, &bin_code, 2);
	param3 = get_param(vm, process, &bin_code, 2);
	value[0] = get_value_param_mod(vm, process, start, param1);
	value[1] = get_value_param_mod(vm, process, start, param2);
	value[2] = param3.value;
	if (param1.type && param2.type && param3.type)
	{
		process->reg[param3.value] =
			get_value_from_vm(vm, get_adress_index(vm, start,
											value[0] + value[1], 1), 4);
		if (vm->param_v)
			verbose_op_load_index(vm, process, start, value);
	}
}

void		op_load_index(t_vm *vm, t_process *process)
{
	unsigned char	bin_code;
	t_pc			start;

	start = process->pc;
	increment_pc(vm, &(process->pc), 1);
	bin_code = (unsigned char)*(process->pc);
	increment_pc(vm, &(process->pc), 1);
	if (check_bin_code(bin_code, 10))
		op_load_exec(vm, process, bin_code, start);
	else
		increment_pc_bin_code(vm, &(process->pc), bin_code, 3 + 20);
}

void		verbose_op_load_index(t_vm *vm, t_process *process, t_pc start,
		int param[3])
{
	verbose_op_header(process);
	ft_printf("ldi %d %d r%d\n", param[0], param[1], param[2]);
	ft_printf("       | -> load from %d + %d = %d (with pc and mod %d)\n",
	param[0], param[1], param[0] + param[1], ((param[0] + param[1]) % IDX_MOD)
	+ start - vm->memory_space);
}
