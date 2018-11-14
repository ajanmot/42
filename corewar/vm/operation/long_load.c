/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_load.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <pgerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 22:11:24 by pgerbaud          #+#    #+#             */
/*   Updated: 2018/03/31 02:14:10 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void		verbose_op_long_load(t_process *process, int value, int reg)
{
	verbose_op_header(process);
	ft_printf("lld %d r%d\n", value, reg);
}

void		op_long_load(t_vm *vm, t_process *process)
{
	unsigned char	bin_code;
	int				value;
	int				reg;
	t_pc			start;

	start = process->pc;
	increment_pc(vm, &(process->pc), 1);
	bin_code = (unsigned char)*(process->pc);
	increment_pc(vm, &(process->pc), 1);
	if (check_bin_code(bin_code, 13))
	{
		value = get_value_param(vm, process, start,
			get_param(vm, process, &bin_code, 4));
		reg = (get_param(vm, process, &bin_code, 4)).value;
		if (reg && reg < REG_NUMBER)
		{
			(process->reg)[reg] = value;
			process->carry = (!value);
			if (vm->param_v)
				verbose_op_long_load(process, value, reg);
		}
	}
	else
		increment_pc_bin_code(vm, &(process->pc), bin_code, 2 + 40);
}
