/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoblech <hsoblech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 22:11:24 by hsoblech          #+#    #+#             */
/*   Updated: 2018/03/30 21:50:52 by hsoblech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void	set_verbose(t_vm *vm, int value)
{
	if (value > 0 && value < 16)
	{
		vm->param_v = (value & V_OP);
		vm->param_c = (value & V_CYCLE);
		vm->param_d = (value & V_DEATH);
		vm->param_ctd = (value & V_CTD);
	}
}

void	verbose_op_header(t_process *process)
{
	ft_printf("P%5d | ", process->pid);
}
