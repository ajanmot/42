/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 16:02:03 by ajanmot           #+#    #+#             */
/*   Updated: 2018/03/30 19:11:30 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

int			ft_free_tab(char **tab, int status)
{
	char	*tmp;
	char	**head;

	head = tab;
	if (!tab)
		return (status);
	while (*tab)
	{
		tmp = *tab;
		tab++;
		ft_free(tmp);
	}
	if (*head)
		ft_free(head);
	head = 0;
	return (status);
}

void		ft_free_label(t_label *label)
{
	t_label *tmp;

	while (label)
	{
		tmp = label;
		label = label->next;
		ft_free(tmp->name);
		ft_free(tmp);
	}
}

void		ft_free_file(t_file *file)
{
	if (file->instructions)
		ft_free_all_instruction(file->instructions);
	if (file->path_cor)
		ft_free(file->path_cor);
	if (file->header)
		ft_free(file->header);
	if (file->label)
		ft_free_label(file->label);
	if (file->fd_s != 0)
		close(file->fd_s);
	if (file)
		ft_free(file);
	file = 0;
}

void		ft_free_all_instruction(t_list *instruction)
{
	t_list *next;

	while (instruction)
	{
		next = instruction->next;
		ft_free_instruction(*((t_instruction **)instruction->content));
		ft_free(instruction->content);
		ft_free(instruction);
		instruction = next;
	}
}

void		ft_free_instruction(t_instruction *instruction)
{
	int counter;

	counter = 0;
	ft_free(instruction->raw_instruction);
	while (counter < instruction->op->nb_params)
	{
		if (instruction->args[counter]->final)
			ft_free(instruction->args[counter]->final);
		if (instruction->args[counter]->initial)
			ft_free(instruction->args[counter]->initial);
		ft_free(instruction->args[counter]);
		counter++;
	}
	ft_free(instruction->args);
	if (instruction->raw_operandes)
		ft_free_tab(instruction->raw_operandes, 0);
	ft_free_tab(instruction->labels, 0);
	ft_free(instruction->final_op_code);
	ft_free(instruction);
}
