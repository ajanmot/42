/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 19:14:35 by ajanmot           #+#    #+#             */
/*   Updated: 2017/11/30 19:14:36 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		ft_nbrlen(uintmax_t nbr, char *base)
{
	size_t			b_value;
	unsigned int	i;

	b_value = ft_strlen(base);
	i = 0;
	if (!nbr)
		return (1);
	while (nbr)
	{
		nbr /= b_value;
		i++;
	}
	return (i);
}
