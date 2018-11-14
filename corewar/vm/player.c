/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoblech <hsoblech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 16:04:52 by hsoblech          #+#    #+#             */
/*   Updated: 2018/03/31 02:21:48 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_player	init_player(int id)
{
	t_player	player;

	player.id = id;
	ft_bzero(player.name, PROG_NAME_LENGTH + 1);
	ft_bzero(player.comment, COMMENT_LENGTH + 1);
	player.file = NULL;
	player.is_alive = 0;
	player.size = 0;
	return (player);
}

void		add_player(t_list **list_players, int id)
{
	t_list		*player;
	t_player	tmp;
	t_list		*current;

	if (get_player_by_id_(*list_players, id))
		id = generate_player_id(*list_players);
	tmp = init_player(id);
	player = ft_lstnew(&tmp, sizeof(t_player));
	current = *list_players;
	if (!(*list_players))
	{
		*list_players = player;
		return ;
	}
	while (current->next)
		current = current->next;
	current->next = player;
}

void		add_player_file(t_list **list_players, char *file)
{
	t_list *current;

	current = *list_players;
	while (current && current->next)
		current = current->next;
	if ((!current || ((t_player*)(current->content))->file))
		add_player(list_players, generate_player_id(*list_players));
	current = *list_players;
	while (current && current->next && ((t_player *)current->content)->file)
		current = current->next;
	((t_player*)(current->content))->file = file;
}

void		load_player(t_vm *vm, t_player *player, int n_player)
{
	int				fd;
	int				start;
	unsigned char	tmp[4];
	unsigned int	size_instruction;

	add_process(vm, player);
	start = (MEM_SIZE / get_n_player(vm->list_players)) * n_player;
	((t_process *)vm->list_process->content)->pc = vm->memory_space + start;
	fd = open(player->file, O_RDONLY);
	if (fd < 1)
		file_error(1, player->file, fd);
	read(fd, &tmp, 4);
	if (!magic_valid(tmp))
		file_error(2, player->file, 0);
	parse_player_name(player, fd);
	read(fd, &tmp, 4);
	read(fd, &tmp, 4);
	size_instruction = (unsigned int)bigendian(tmp, 4);
	player->size = size_instruction;
	parse_player_comment(player, fd);
	check_error_player(vm, player, n_player, fd);
}

void		load_players(t_vm *vm)
{
	t_list		*current;
	t_player	*player;
	int			i;

	i = 0;
	current = vm->list_players;
	while (current)
	{
		player = ((t_player*)current->content);
		load_player(vm, player, i);
		current = current->next;
		i++;
	}
}
