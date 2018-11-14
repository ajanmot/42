/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 21:40:24 by ajanmot           #+#    #+#             */
/*   Updated: 2018/03/30 19:10:49 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

int		ft_error_asm(char *str, t_file *file, void *to_free)
{
	if (file)
		ft_printf(C_RED"ERROR line %d. \nLog: %s\n"C_NONE, file->current_line,
str);
	if (file)
		ft_free_file(file);
	if (to_free)
		ft_free(to_free);
	exit(1);
}
