/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoblech <hsoblech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 10:18:44 by hsoblech          #+#    #+#             */
/*   Updated: 2018/03/30 22:14:43 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		increment_pc_bin_code(t_vm *vm, t_pc *pc, unsigned char code,
		int n_arg)
{
	int type;
	int i;
	int size_dir;

	i = 0;
	size_dir = n_arg / 10;
	n_arg %= 10;
	while (i < n_arg)
	{
		type = arg_type(code);
		if (type == T_DIR)
			increment_pc(vm, pc, size_dir);
		else if (type == T_IND)
			increment_pc(vm, pc, 2);
		else if (type == T_REG)
			increment_pc(vm, pc, 1);
		code <<= 2;
		i++;
	}
}

int			check_code_one_arg(unsigned char code, int flags)
{
	int type;

	type = arg_type(code);
	if ((flags & T_DIR) && type == T_DIR)
		return (1);
	if ((flags & T_IND) && type == T_IND)
		return (1);
	if ((flags & T_REG) && type == T_REG)
		return (1);
	return (0);
}

int			check_bin_code_bis(unsigned char code, int op)
{
	if (op == 11)
		if (check_code_one_arg(code, T_REG) && (code <<= 2))
			if (check_code_one_arg(code, T_REG | T_DIR | T_IND) &&
					(code <<= 2))
				return (check_code_one_arg(code, T_REG | T_DIR));
	if (op == 13)
		if (check_code_one_arg(code, T_DIR | T_IND) && (code <<= 2))
			return (check_code_one_arg(code, T_REG));
	if (op == 14)
		if (check_code_one_arg(code, T_REG | T_DIR | T_IND) && (code <<= 2))
			if (check_code_one_arg(code, T_REG | T_DIR) && (code <<= 2))
				return (check_code_one_arg(code, T_REG));
	if (op == 16)
		return (check_code_one_arg(code, T_REG));
	return (0);
}

int			check_bin_code(unsigned char code, int op)
{
	if (op == 2)
		if (check_code_one_arg(code, T_IND | T_DIR) && (code <<= 2))
			return (check_code_one_arg(code, T_REG));
	if (op == 3)
		if (check_code_one_arg(code, T_REG) && (code <<= 2))
			return (check_code_one_arg(code, T_REG | T_IND));
	if (op == 4 || op == 5)
		if (check_code_one_arg(code, T_REG) && (code <<= 2))
			if (check_code_one_arg(code, T_REG) && (code <<= 2))
				return (check_code_one_arg(code, T_REG));
	if (op == 6 || op == 7 || op == 8)
		if (check_code_one_arg(code, T_REG | T_DIR | T_IND) && (code <<= 2))
			if (check_code_one_arg(code, T_REG | T_DIR | T_IND) &&
					(code <<= 2))
				return (check_code_one_arg(code, T_REG));
	if (op == 10)
		if (check_code_one_arg(code, T_REG | T_DIR | T_IND) && (code <<= 2))
			if (check_code_one_arg(code, T_REG | T_DIR) && (code <<= 2))
				return (check_code_one_arg(code, T_REG));
	return (check_bin_code_bis(code, op));
}
