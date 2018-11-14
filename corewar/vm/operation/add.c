/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <pgerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 22:11:24 by pgerbaud          #+#    #+#             */
/*   Updated: 2018/03/30 20:42:59 by hsoblech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void	op_addition(t_vm *vm, t_process *process)
{
	unsigned char	bin_code;
	t_param			param1;
	t_param			param2;
	t_param			param3;

	increment_pc(vm, &(process->pc), 1);
	bin_code = (unsigned char)*(process->pc);
	increment_pc(vm, &(process->pc), 1);
	if (check_bin_code(bin_code, 4))
	{
		param1 = get_param_w_type(vm, process, T_REG, 4);
		param2 = get_param_w_type(vm, process, T_REG, 4);
		param3 = get_param_w_type(vm, process, T_REG, 4);
		if (param1.type && param2.type && param3.type)
		{
			process->reg[param3.value] =
				process->reg[param1.value] + process->reg[param2.value];
			process->carry = (!(process->reg[param2.value]));
			if (vm->param_v)
				verbose_op_add(process, param1.value,
					param2.value, param3.value);
		}
	}
	else
		increment_pc_bin_code(vm, &(process->pc), bin_code, 3 + 40);
}

void	verbose_op_add(t_process *process, int reg1, int reg2, int reg3)
{
	verbose_op_header(process);
	ft_printf("add r%d r%d r%d\n", reg1, reg2, reg3);
}
