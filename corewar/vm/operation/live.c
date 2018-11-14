/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <pgerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 22:11:24 by pgerbaud          #+#    #+#             */
/*   Updated: 2018/03/30 19:57:35 by hsoblech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void	op_alive(t_vm *vm, t_process *process)
{
	t_player	*player;
	int			id;

	increment_pc(vm, &(process->pc), 1);
	id = get_param_w_type(vm, process, T_DIR, 4).value;
	(process->is_alive)++;
	process->last_live = vm->total_cycle;
	if (vm->param_v)
		verbose_op_live(process, id);
	if (!(player = get_player_by_id(vm, id)))
		return ;
	verbose_live(player);
	(player->is_alive)++;
	vm->winner = player;
}

void	verbose_live(t_player *player)
{
	ft_printf("Player %d(%s) is said to be alive\n", player->id, player->name);
}

void	verbose_op_live(t_process *process, int live)
{
	verbose_op_header(process);
	ft_printf("live %d\n", live);
}
