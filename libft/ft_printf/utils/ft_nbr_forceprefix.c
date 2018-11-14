/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_forceprefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:54:15 by ajanmot           #+#    #+#             */
/*   Updated: 2017/11/30 18:54:16 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

ssize_t			ft_nbr_forceprefix(uintmax_t nbr, char *base, t_spec *spec,
		char *prefix)
{
	unsigned	nbrlen;
	size_t		result_size;

	nbrlen = ft_calc_nbrlen(nbr, base, NULL, spec) + ft_strlen(prefix);
	result_size = ft_strlen(prefix);
	if (spec->got_width && !spec->right_pad && !spec->zeroes_pad)
	{
		ft_width_pad(nbrlen, spec->width, ' ');
		result_size += ft_max(spec->width - nbrlen, 0);
		spec->got_width = 0;
	}
	else if (spec->got_width)
		spec->width -= ft_strlen(prefix);
	ft_putstr(prefix);
	return (ft_handle_uint(nbr, spec, base, NULL) + result_size);
}
