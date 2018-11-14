/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushparams.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 10:46:57 by ajanmot           #+#    #+#             */
/*   Updated: 2017/11/17 10:47:35 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpushparams(int ac, char **av)
{
	int		current;
	t_list	*begin_list;

	current = 0;
	begin_list = 0;
	while (current < ac)
	{
		ft_lstpushfront(&begin_list, av[current]);
		current++;
	}
	return (begin_list);
}
