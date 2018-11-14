/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 18:31:31 by tkeynes           #+#    #+#             */
/*   Updated: 2018/03/30 18:31:59 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"
#include "../../both/op.h"

int			ft_is_op(char **tab, t_file *file)
{
	int i;

	if (!tab || !*tab)
		return (-1);
	i = 0;
	while (i < 16)
	{
		if (!ft_strcmp(*tab, g_op_tab[i].name))
			break ;
		i++;
	}
	if (i == 17)
	{
		ft_free_tab(tab, 1);
		ft_error_asm("Aucune operation ne correspond\n", file, 0);
	}
	return (i);
}
