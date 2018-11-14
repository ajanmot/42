/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_label_gen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 18:19:43 by tkeynes           #+#    #+#             */
/*   Updated: 2018/03/30 18:38:48 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"
#include "../../both/op.h"

unsigned char		*get_memory_gap_labels(t_file *file, t_list *begin_list,
t_list *current, t_operande *label_to_find)
{
	t_list			*label_to_find_lst;
	int				pos1;
	int				pos2;
	unsigned char	*final;

	if (!(label_to_find_lst = get_ins_lab(begin_list, label_to_find->initial)))
		ft_error_asm("Error label - get_memory_gap_labels\n", file, 0);
	pos2 = get_position_of_instruction(begin_list,
(*((t_instruction **)(label_to_find_lst->content))));
	pos1 = get_position_of_instruction(begin_list,
(*((t_instruction **)(current->content))));
	if (pos1 > pos2)
		final = int_to_bytes(file, -1 * ((weight_beetween_instruction(
label_to_find_lst, current))), label_to_find->byte_size);
	else
		final = int_to_bytes(file, weight_beetween_instruction(current,
label_to_find_lst), label_to_find->byte_size);
	return (final);
}

t_list				*get_ins_lab(t_list *list, char *label_to_find)
{
	int		i;
	char	**tab_labels;

	while (list)
	{
		tab_labels = (*((t_instruction **)list->content))->labels;
		if (tab_labels)
		{
			i = 0;
			while (tab_labels[i])
			{
				if (!ft_strcmp(ft_strchr(label_to_find, LABEL_CHAR) + 1,
(tab_labels[i])))
					return (list);
				i++;
			}
		}
		list = list->next;
	}
	return (0);
}
