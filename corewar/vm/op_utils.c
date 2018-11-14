/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <pgerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 19:33:25 by pgerbaud          #+#    #+#             */
/*   Updated: 2018/03/30 22:15:02 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			bigendian(unsigned char *array, int nb_octet)
{
	unsigned int	j;
	int				i;

	i = 0;
	j = 0;
	while (i < nb_octet)
	{
		j = (j << 8) + array[i];
		i++;
	}
	return (j);
}

int			get_value_from_vm(t_vm *vm, t_pc pc, int size)
{
	int		result;

	memcpy_cuted_form_vm(&result, vm, pc, size);
	result = bigendian((unsigned char*)&result, size);
	return (result);
}

void		memcpy_cuted_form_vm(void *dest, t_vm *vm, t_pc pc, int size)
{
	int	i;

	i = 0;
	if (pc >= vm->memory_space + MEM_SIZE - 1)
		increment_pc(vm, &pc, 1);
	while (i < size)
	{
		((unsigned char*)(dest))[i] = *pc;
		i++;
		increment_pc(vm, &pc, 1);
	}
}

void		memcpy_cuted_to_vm(void *src, t_vm *vm, t_pc pc, int size)
{
	int	i;

	i = 0;
	if (pc >= vm->memory_space + MEM_SIZE - 1)
		increment_pc(vm, &pc, 1);
	while (size > 0)
	{
		*pc = ((unsigned char*)(src))[size - 1];
		size--;
		increment_pc(vm, &pc, 1);
	}
}

int			arg_type(unsigned char bin_code)
{
	unsigned char	result;

	result = bin_code >> 7;
	if (result & 1)
	{
		result = bin_code >> 6;
		if (result & 1)
			return (T_IND);
		else
			return (T_DIR);
	}
	else
	{
		result = bin_code >> 6;
		if (result & 1)
			return (T_REG);
		else
			return (0);
	}
}
