/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <pgerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 22:11:24 by pgerbaud          #+#    #+#             */
/*   Updated: 2018/03/30 21:48:24 by hsoblech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void	op_store_exec(t_vm *vm, t_process *process,
	unsigned char bin_code, t_pc start)
{
	t_param			param1;
	t_param			param2;
	int				value;

	param1 = get_param(vm, process, &bin_code, 4);
	param2 = get_param(vm, process, &bin_code, 4);
	if (param1.type && param2.type)
	{
		value = get_value_param_mod(vm, process, start, param1);
		if (param2.type == T_REG && param2.value && param2.value < REG_NUMBER)
		{
			process->reg[param2.value] = value;
			if (vm->param_v)
				verbose_op_store(process, param1.value, param2.value);
		}
		else
		{
			memcpy_cuted_to_vm(&value, vm,
					get_adress_index(vm, start,
						(short)(param2.value), 1), REG_SIZE);
			if (vm->param_v)
				verbose_op_store(process, param1.value, (short)param2.value);
		}
	}
}

void	op_store(t_vm *vm, t_process *process)
{
	unsigned char	bin_code;
	t_pc			start;

	start = process->pc;
	increment_pc(vm, &(process->pc), 1);
	bin_code = (unsigned char)*(process->pc);
	increment_pc(vm, &(process->pc), 1);
	if (check_bin_code(bin_code, 3))
		op_store_exec(vm, process, bin_code, start);
	else
		increment_pc_bin_code(vm, &(process->pc), bin_code, 2 + 40);
}

void	verbose_op_store(t_process *process, int param1, int param2)
{
	verbose_op_header(process);
	ft_printf("st r%d %d\n", param1, param2);
}
