/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <pgerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 19:33:25 by pgerbaud          #+#    #+#             */
/*   Updated: 2018/03/31 03:27:42 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

int			get_cycle_op(int op)
{
	if (op == 1 || op == 4 || op == 5 || op == 13)
		return (10);
	if (op == 2 || op == 3)
		return (5);
	if (op == 6 || op == 7 || op == 8)
		return (6);
	if (op == 9)
		return (20);
	if (op == 10 || op == 11)
		return (25);
	if (op == 12)
		return (800);
	if (op == 14)
		return (50);
	if (op == 15)
		return (1000);
	if (op == 16)
		return (2);
	return (0);
}

t_param		get_param(t_vm *vm, t_process *process, unsigned char *bin_code,
		int size_dir)
{
	t_param			param;
	int				size;

	size = 2;
	ft_bzero(&param, sizeof(t_param));
	param.type = arg_type(*bin_code);
	if (param.type == T_REG)
	{
		param.value = (unsigned char)(*(process->pc));
		if (!param.value || param.value > REG_NUMBER)
			param.type = 0;
		increment_pc(vm, &(process->pc), 1);
	}
	else
	{
		if (param.type == T_DIR)
			size = size_dir;
		param.value = get_value_from_vm(vm, process->pc, size);
		increment_pc(vm, &(process->pc), size);
	}
	(*bin_code) <<= 2;
	return (param);
}

t_param		get_param_w_type(t_vm *vm, t_process *process, int type,
		int size_dir)
{
	t_param			param;
	int				size;

	size = 2;
	param.type = type;
	if (param.type == T_REG)
	{
		param.value = (unsigned char)(*(process->pc));
		if (!param.value || param.value > REG_NUMBER)
			param.type = 0;
		increment_pc(vm, &(process->pc), 1);
	}
	else
	{
		if (param.type == T_DIR)
			size = size_dir;
		param.value = get_value_from_vm(vm, process->pc, size);
		increment_pc(vm, &(process->pc), size);
	}
	return (param);
}

int			get_value_param(t_vm *vm, t_process *process, t_pc pc, t_param arg)
{
	unsigned char	*adress;
	short			cast;

	if (arg.type == T_REG && arg.value <= 16)
		return ((process->reg)[arg.value]);
	else if (arg.type == T_DIR)
	{
		cast = arg.value;
		return (cast);
	}
	else if (arg.type == T_IND)
	{
		adress = get_adress_index(vm, pc, arg.value, 0);
		return (get_value_from_vm(vm, adress, 4));
	}
	return (0);
}

int			get_value_param_mod(t_vm *vm, t_process *process, t_pc pc,
		t_param arg)
{
	unsigned char	*adress;
	short			cast;

	if (arg.type == T_REG && arg.value <= 16)
		return ((process->reg)[arg.value]);
	else if (arg.type == T_DIR)
	{
		cast = arg.value;
		return (cast);
	}
	else if (arg.type == T_IND)
	{
		adress = get_adress_index(vm, pc, arg.value, 1);
		return (get_value_from_vm(vm, adress, 4));
	}
	return (0);
}
