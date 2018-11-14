/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operande.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 18:32:10 by tkeynes           #+#    #+#             */
/*   Updated: 2018/03/31 02:58:57 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"
#include "../../both/op.h"

t_operande		*new_operande(t_file *file, char *operande,
		t_instruction *instruction)
{
	t_operande	*op;

	if (!(op = (t_operande *)ft_calloc(sizeof(t_operande))))
		ft_error_asm("ft_calloc error", file, operande);
	if (!(op->initial = ft_strdup(operande)))
		ft_error_asm("Error malloc", file, op);
	op->type = ft_detect_type(file, operande);
	op->n = instruction->op->opcode;
	op->final = generate_operande(file, op, instruction);
	return (op);
}

void			generate_label_operandes(t_file *file, t_list *instructions)
{
	t_instruction	*current_instruction;
	int				counter;
	int				total_bytes;

	total_bytes = 0;
	counter = 0;
	while (instructions)
	{
		current_instruction = (*((t_instruction **)instructions->content));
		total_bytes += current_instruction->nb_octets;
		while (counter < current_instruction->op->nb_params)
		{
			if (current_instruction->args[counter]->type == T_LAB)
			{
				ft_free(current_instruction->args[counter]->final);
				current_instruction->args[counter]->final =
get_memory_gap_labels(file, file->instructions, instructions,
current_instruction->args[counter]);
			}
			counter++;
		}
		counter = 0;
		instructions = instructions->next;
	}
	file->header->prog_size = total_bytes;
}

t_operande		**new_operande_struct(t_file *file, t_instruction *instruction)
{
	t_operande	**final;
	char		**splitted_operandes;
	int			pos;

	pos = 0;
	splitted_operandes = instruction->raw_operandes;
	if (!(final = (t_operande **)ft_calloc(sizeof(t_operande*) *
					((instruction->op)->nb_params + 1))))
		ft_error_asm("Error ft_calloc struct t_instruction", file, 0);
	while (*splitted_operandes)
	{
		final[pos] = new_operande(file, *splitted_operandes, instruction);
		(splitted_operandes)++;
		pos++;
	}
	return (final);
}

int				ft_detect_type(t_file *file, char *operande)
{
	int res;

	if (*operande == 'r')
	{
		res = ft_atol(operande + 1);
		if (ft_strisdigit(operande + 1) && res >= 0 && res <= REG_NUMBER)
			return (T_REG);
	}
	else if (*operande == DIRECT_CHAR)
	{
		if (((*(operande + 1) == LABEL_CHAR) && ft_is_label_valid(operande + 1
) && ft_is_label_exist(file, operande + 2)) || ft_strisnumber(operande + 1))
			return (T_DIR);
	}
	else if (*operande == LABEL_CHAR)
	{
		if (((*(operande) == LABEL_CHAR) && ft_is_label_valid(operande) &&
ft_is_label_exist(file, operande + 1)) || ft_strisnumber(operande))
			return (T_IND);
	}
	else if (((*(operande) == LABEL_CHAR) && ft_is_label_valid(operande) &&
ft_is_label_exist(file, operande)) || ft_strisnumber(operande))
		return (T_IND);
	return (0);
}
