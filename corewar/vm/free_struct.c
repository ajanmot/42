/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 13:28:18 by tkeynes           #+#    #+#             */
/*   Updated: 2018/03/30 19:54:29 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		free_op(void *proc, size_t size)
{
	t_list		*tmp;
	t_list		*current;

	(void)size;
	tmp = ((t_process *)proc)->list_op;
	current = tmp;
	while (current)
	{
		tmp = tmp->next;
		free(current->content);
		free(current);
		current = tmp;
	}
	free(proc);
}

void		free_all(t_vm *vm)
{
	t_list		*tmp;
	t_list		*current;
	int			i;

	i = 0;
	tmp = vm->list_process;
	current = tmp;
	while (current)
	{
		tmp = tmp->next;
		free_op(current->content, 0);
		free(current);
		current = tmp;
	}
	tmp = vm->list_players;
	current = tmp;
	while (current)
	{
		tmp = tmp->next;
		free(current->content);
		free(current);
		current = tmp;
	}
}
