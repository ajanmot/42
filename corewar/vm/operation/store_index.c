/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <pgerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 22:11:24 by pgerbaud          #+#    #+#             */
/*   Updated: 2018/03/31 02:18:22 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void	op_store_index_exec(t_vm *vm, t_process *process,
	unsigned char bin_code, t_pc start)
{
	int					value[4];
	t_param				param1;
	t_param				param2;
	t_param				param3;

	param1 = get_param(vm, process, &bin_code, 2);
	param2 = get_param(vm, process, &bin_code, 2);
	param3 = get_param(vm, process, &bin_code, 2);
	if (param1.type && param2.type && param3.type)
	{
		value[0] = get_value_param_mod(vm, process, start, param1);
		value[1] = get_value_param_mod(vm, process, start, param2);
		value[2] = get_value_param_mod(vm, process, start, param3);
		value[3] = param1.value;
		memcpy_cuted_to_vm(&(value[0]), vm, get_adress_index(vm, start,
					value[1] + value[2], 1), REG_SIZE);
		if (vm->param_v)
			verbose_op_store_index(vm, process, start, value);
	}
}

void	op_store_index(t_vm *vm, t_process *process)
{
	unsigned char		bin_code;
	t_pc				start;

	start = process->pc;
	increment_pc(vm, &(process->pc), 1);
	bin_code = (unsigned char)*(process->pc);
	increment_pc(vm, &(process->pc), 1);
	if (check_bin_code(bin_code, 11))
		op_store_index_exec(vm, process, bin_code, start);
	else
		increment_pc_bin_code(vm, &(process->pc), bin_code, 3 + 20);
}

void	verbose_op_store_index(t_vm *vm, t_process *process, t_pc start,
		int p[4])
{
	verbose_op_header(process);
	ft_printf("sti r%d %d %d\n", p[3], p[1], p[2]);
	ft_printf("       | -> store to %d + %d = %d (with pc and mod %d)\n",
				p[1], p[2], p[1] + p[2], ((p[1] + p[2]) % IDX_MOD)
				+ start - vm->memory_space);
}
