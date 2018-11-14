/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <pgerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 16:45:33 by pgerbaud          #+#    #+#             */
/*   Updated: 2018/03/30 23:45:16 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		end_game(t_vm *vm)
{
	if (vm->winner)
		ft_printf("Le joueur %d(%s) a gagné\n", vm->winner->id,
				vm->winner->name);
	else
		ft_printf("Aucun joueur n'a été rapporté alive\n");
	free_all(vm);
	exit(0);
}

void		end_dump(t_vm *vm)
{
	dump_memory(vm);
	free_all(vm);
	exit(0);
}

void		error_parsing(char *message)
{
	if (message)
		ft_printf("%s\n", message);
	exit(-1);
}

void		file_error(int i, char *file, int fd)
{
	if (i == 1)
		ft_printf("%s can't be open (%d)\n", file, fd);
	if (i == 2)
		ft_printf("Le fichier %s n'est pas compatible\n", file);
	if (i == 3)
		ft_printf("%s is too big\n", file);
	if (i == 3)
		ft_printf("%s is too small\n", file);
	exit(-1);
}
