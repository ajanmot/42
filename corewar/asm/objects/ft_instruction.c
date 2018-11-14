/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 18:06:47 by tkeynes           #+#    #+#             */
/*   Updated: 2018/03/30 18:10:17 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"
#include "../../both/op.h"

int					get_nb_bytes_instruction(t_instruction *instruction)
{
	int			final;
	t_operande	**operandes;
	int			counter;

	counter = 0;
	final = 0;
	final += 1;
	final += instruction->op->has_pcode;
	operandes = instruction->args;
	while (counter < instruction->op->nb_params)
	{
		final += operandes[counter]->byte_size;
		counter++;
	}
	return (final);
}

int					get_position_of_instruction(t_list *list,
t_instruction *to_find)
{
	int				i;
	t_instruction	*current;

	i = 0;
	while (list)
	{
		current = (*((t_instruction **)list->content));
		if (current == to_find)
			return (i);
		list = list->next;
		i++;
	}
	return (-1);
}

int					weight_beetween_instruction(t_list *first, t_list *second)
{
	t_list	*l;
	int		res;

	l = first;
	res = 0;
	while (l != second)
	{
		res += (*((t_instruction **)l->content))->nb_octets;
		l = l->next;
	}
	return (res);
}

t_instruction		*new_instruction(t_file *file, char *raw_instruction,
char **splitted_instruction, char **labels)
{
	t_instruction		*instruction;
	char				*str;

	if (!(str = ft_strdup(splitted_instruction[1])))
		ft_error_asm("Error malloc", file, 0);
	if (!(instruction = (t_instruction*)ft_calloc(sizeof(t_instruction))))
		ft_error_asm("error ft_calloc", file, str);
	if (!(instruction->raw_instruction = ft_strdup(raw_instruction)))
		ft_error_asm("Error malloc", file, str);
	if (!(instruction->raw_operandes = ft_strsplit(str, SEPARATOR_CHAR)))
		ft_error_asm("Error strsplit", file, str);
	instruction->labels = labels;
	instruction->op = &g_op_tab[ft_is_op(splitted_instruction, file)];
	instruction->args = new_operande_struct(file, instruction);
	instruction->ocp = reverse_bits(generate_ocp(file, instruction, 0));
	instruction->nb_octets = get_nb_bytes_instruction(instruction);
	instruction->is_ready = 0;
	instruction->final_op_code = int_to_bytes(file, (instruction->op)->opcode,
1);
	ft_free(str);
	return (instruction);
}
