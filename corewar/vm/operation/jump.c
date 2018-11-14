/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <pgerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 22:11:24 by pgerbaud          #+#    #+#             */
/*   Updated: 2018/03/30 21:55:48 by hsoblech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void	op_jump(t_vm *vm, t_process *process)
{
	short	cast;

	increment_pc(vm, &(process->pc), 1);
	cast = get_param_w_type(vm, process, T_DIR, 2).value;
	if (process->carry)
	{
		decrement_pc(vm, &(process->pc), 3);
		if (cast > 0)
			increment_pc(vm, &(process->pc), cast);
		else
			decrement_pc(vm, &(process->pc), -cast);
		if (vm->param_v)
			verbose_op_jump(process, cast, 1);
	}
	else
	{
		if (vm->param_v)
			verbose_op_jump(process, cast, 0);
	}
}

void	verbose_op_jump(t_process *process, short int value, int ok)
{
	verbose_op_header(process);
	if (ok)
		ft_printf("zjmp %d OK\n", value);
	else
		ft_printf("zjmp %d FAILED\n", value);
}
