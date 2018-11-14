/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 21:26:14 by ajanmot           #+#    #+#             */
/*   Updated: 2018/03/30 19:24:50 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/include.h"

int			main(int argc, char **argv)
{
	t_file	*file;
	int		current_file;

	if (argc == 1)
	{
		ft_printf(C_RED"Veuillez entrer un nombre de fichier valide\n"C_NONE);
		ft_error_asm("Veuillez entrer un nombre de fichier valide\n", 0, 0);
	}
	current_file = 1;
	file = 0;
	while (current_file < argc)
	{
		file = ft_init_file();
		ft_handle_file(file, argv[current_file]);
		parse_file(file);
		generate_label_operandes(file, file->instructions);
		check_last_char_new_line(file);
		if (file->header->prog_size == 0)
			ft_error_asm("No instructions...", file, 0);
		write_file(file);
		current_file++;
		ft_free_file(file);
	}
}
