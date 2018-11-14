/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <pgerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 13:29:11 by pgerbaud          #+#    #+#             */
/*   Updated: 2018/03/31 02:13:31 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		main(int argc, char **argv)
{
	t_vm vm;

	if (argc < 2)
	{
		ft_printf("Usage: %s [-dump nbr_cycles] [[-n number] champion1.cor"
		"[-v N]]\n\t\t-v N: Verbosity levels (between 1 and 15),"
		"can be added together to enable several\n\t\t\t- 1 Show Cycle\n "
		"\t\t\t- 2 Show Operation \n \t\t\t- 4 Show Death\n \t\t\t"
		"- 8 Show Cycle To Die Change\n"
		, argv[0]);
		return (0);
	}
	vm = parse_arg(argc, argv);
	if (!vm.list_players)
	{
		ft_printf("No player load...\n");
		return (0);
	}
	load_players(&vm);
	ft_printf("Introducing contestants...\n");
	dump_players(vm.list_players);
	ft_printf(C_RED"Start playing...\n"C_NONE);
	exec_cycle(&vm);
	return (0);
}
