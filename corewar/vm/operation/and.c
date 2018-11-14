/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <pgerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 22:11:24 by pgerbaud          #+#    #+#             */
/*   Updated: 2018/03/31 03:25:21 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

static void	op_and_exec(t_vm *vm, t_process *process, unsigned char bin_code,
t_pc start)
{
	t_param			param1;
	t_param			param2;
	t_param			param3;
	int				value1;
	int				value2;

	param1 = get_param(vm, process, &bin_code, 4);
	param2 = get_param(vm, process, &bin_code, 4);
	param3 = get_param(vm, process, &bin_code, 4);
	value1 = get_value_param_mod(vm, process, start, param1);
	value2 = get_value_param_mod(vm, process, start, param2);
	if (param1.type && param2.type && param3.type)
	{
		process->reg[param3.value] = value1 & value2;
		process->carry = (!(process->reg[param3.value]));
		if (vm->param_v)
			verbose_op_and(process, value1, value2, param3.value);
	}
}

void		op_and(t_vm *vm, t_process *process)
{
	unsigned char	bin_code;
	t_pc			start;

	start = process->pc;
	increment_pc(vm, &(process->pc), 1);
	bin_code = (unsigned char)*(process->pc);
	increment_pc(vm, &(process->pc), 1);
	if (check_bin_code(bin_code, 6))
		op_and_exec(vm, process, bin_code, start);
	else
		increment_pc_bin_code(vm, &(process->pc), bin_code, 3 + 40);
}

void		verbose_op_and(t_process *process, int param1, int param2, int reg)
{
	verbose_op_header(process);
	ft_printf("and %d %d r%d\n", param1, param2, reg);
}
