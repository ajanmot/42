/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cycle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <pgerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 13:28:18 by pgerbaud          #+#    #+#             */
/*   Updated: 2018/03/30 19:52:42 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	check_players_alive(t_vm *vm, t_list **process)
{
	t_list	*current_player;
	t_list	*first_process;
	t_list	*tmp_process;

	current_player = vm->list_players;
	first_process = *process;
	tmp_process = *process;
	while (current_player)
	{
		while (first_process)
		{
			if (((t_player *)current_player->content)->id == ((t_player *)
						((t_process *)first_process->content)->player)->id)
				return ;
			first_process = first_process->next;
		}
		first_process = tmp_process;
		current_player = current_player->next;
	}
	end_game(vm);
}

void	check_process_alive(t_list **process, t_list *current, int ctd,
		t_vm *vm)
{
	if (((t_process *)current->content)->is_alive > 0)
		((t_process *)current->content)->is_alive = 0;
	else
	{
		if (vm->param_d)
			ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
					((t_process *)current->content)->pid, vm->total_cycle -
					((t_process *)current->content)->last_live, ctd);
		ft_lst_remove_item(process, current, &free_op);
	}
}

void	check_cycletodie(t_vm *vm, t_list *current)
{
	if (alive_count(vm) >= NBR_LIVE || vm->nbr_last_cycletodie_change >= 10)
	{
		if (vm->nbr_last_cycletodie_change >= 10)
			vm->nbr_last_cycletodie_change = 1;
		vm->cycle_to_die -= CYCLE_DELTA;
		if (vm->param_ctd)
			ft_printf("Cycle to die is now %d\n", vm->cycle_to_die);
	}
	else
		vm->nbr_last_cycletodie_change++;
	vm->nbr_cycle = 0;
	while (current)
	{
		check_process_alive(&(vm->list_process), current, vm->cycle_to_die, vm);
		current = current->next;
	}
	check_players_alive(vm, &vm->list_process);
}
