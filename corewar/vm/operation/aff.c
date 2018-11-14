/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <pgerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 22:11:24 by pgerbaud          #+#    #+#             */
/*   Updated: 2018/03/30 20:36:10 by hsoblech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void	op_aff(t_vm *vm, t_process *process)
{
	unsigned char	bin_code;
	int				value;

	increment_pc(vm, &(process->pc), 1);
	bin_code = (unsigned char)*(process->pc);
	increment_pc(vm, &(process->pc), 1);
	if (check_bin_code(bin_code, 16))
	{
		value = get_value_param_mod(vm, process, process->pc,
			get_param_w_type(vm, process, T_REG, 4));
		ft_putstr("Aff :");
		ft_putchar(value % 256);
		ft_putchar('\n');
	}
	else
		increment_pc_bin_code(vm, &(process->pc), bin_code, 3 + (10 * 4));
}
