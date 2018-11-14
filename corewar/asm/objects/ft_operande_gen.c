/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operande_gen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 18:37:09 by tkeynes           #+#    #+#             */
/*   Updated: 2018/03/30 18:38:02 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"
#include "../../both/op.h"

unsigned char	*generate_reg_operande(t_file *file, t_operande *operande)
{
	operande->byte_size = 1;
	operande->final = int_to_bytes(file, ft_atol(operande->initial + 1), 1);
	return (operande->final);
}

unsigned char	*generate_dir_operande(t_file *file, t_operande *operande,
t_instruction *instruction)
{
	if (instruction->op->has_idx == 1)
		operande->byte_size = 2;
	else
		operande->byte_size = 4;
	if (operande->initial[1] == LABEL_CHAR)
	{
		operande->is_label = 1;
		operande->type = T_LAB;
	}
	else
		operande->final = int_to_bytes(file, ft_atol(operande->initial + 1),
operande->byte_size);
	return (operande->final);
}

unsigned char	*generate_ind_operande(t_file *file, t_operande *operande)
{
	operande->byte_size = 2;
	if (*(operande->initial) == LABEL_CHAR)
	{
		operande->is_label = 1;
		operande->type = T_LAB;
	}
	operande->final = int_to_bytes(file, ft_atol(operande->initial), 2);
	return (operande->final);
}

unsigned char	*generate_operande(t_file *file, t_operande *operande,
t_instruction *instruction)
{
	if ((operande)->type == T_REG)
		return (generate_reg_operande(file, operande));
	else if ((operande)->type == T_DIR)
		return (generate_dir_operande(file, operande, instruction));
	else if ((operande)->type == T_IND)
		return (generate_ind_operande(file, operande));
	return ((operande)->final);
}
