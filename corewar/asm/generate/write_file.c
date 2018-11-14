/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 18:04:27 by tkeynes           #+#    #+#             */
/*   Updated: 2018/03/30 18:05:51 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"
#include <stdio.h>
#include <stdlib.h>

void		write_name(t_file *file, int output_fd)
{
	char	name[PROG_NAME_LENGTH + 4];

	ft_bzero(name, (size_t)PROG_NAME_LENGTH + 4);
	ft_strcpy(name, file->header->prog_name);
	write(output_fd, name, PROG_NAME_LENGTH + 4);
}

void		write_comment(t_file *file, int output_fd)
{
	char	comment[COMMENT_LENGTH + 4];

	ft_bzero(comment, (size_t)COMMENT_LENGTH + 4);
	ft_strcpy(comment, file->header->comment);
	write(output_fd, comment, COMMENT_LENGTH + 4);
}

void		write_instructions(t_file *file, int output_fd)
{
	t_instruction	*current_instruction;
	t_list			*current;
	int				counter;
	t_operande		*current_operande;

	counter = 0;
	current = file->instructions;
	while (current)
	{
		current_instruction = *((t_instruction **)(current->content));
		write(output_fd, (current_instruction->final_op_code), 1);
		if (current_instruction->op->has_pcode)
			write(output_fd, &(current_instruction->ocp), 1);
		while (current_instruction->args[counter] != 0)
		{
			current_operande = current_instruction->args[counter];
			write(output_fd, (current_operande->final),
current_operande->byte_size);
			counter++;
		}
		current = current->next;
		counter = 0;
	}
}

void		write_file(t_file *file)
{
	int		output_fd;
	int		tmp;

	output_fd = open(file->path_cor, O_CREAT | O_RDWR, S_IWUSR | S_IRUSR |
S_IXUSR);
	tmp = rev_indian(file->header->magic);
	write(output_fd, &(tmp), 4);
	write_name(file, output_fd);
	tmp = rev_indian(file->header->prog_size);
	write(output_fd, &(tmp), 4);
	write_comment(file, output_fd);
	write_instructions(file, output_fd);
}
