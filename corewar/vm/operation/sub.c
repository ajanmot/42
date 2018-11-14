/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <pgerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 22:11:24 by pgerbaud          #+#    #+#             */
/*   Updated: 2018/03/30 21:50:33 by hsoblech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void	op_substraction(t_vm *vm, t_process *process)
{
	unsigned char	bin_code;
	t_param			p1;
	t_param			param2;
	t_param			param3;

	increment_pc(vm, &(process->pc), 1);
	bin_code = (unsigned char)*(process->pc);
	increment_pc(vm, &(process->pc), 1);
	if (check_bin_code(bin_code, 5))
	{
		p1 = get_param_w_type(vm, process, T_REG, 4);
		param2 = get_param_w_type(vm, process, T_REG, 4);
		param3 = get_param_w_type(vm, process, T_REG, 4);
		if (p1.type && param2.type && param3.type)
		{
			process->reg[param3.value] =
					process->reg[p1.value]
					- process->reg[param2.value];
			process->carry = (!(process->reg[param2.value]));
			if (vm->param_v)
				verbose_op_sub(process, p1.value, param2.value, param3.value);
		}
	}
	else
		increment_pc_bin_code(vm, &(process->pc), bin_code, 3 + 40);
}

void	verbose_op_sub(t_process *process, int reg1, int reg2, int reg3)
{
	verbose_op_header(process);
	ft_printf("sub r%d r%d r%d\n", reg1, reg2, reg3);
}
