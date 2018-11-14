/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_nbrlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:54:06 by ajanmot           #+#    #+#             */
/*   Updated: 2017/11/30 18:54:07 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

unsigned int		ft_calc_nbrlen(uintmax_t nbr, char *base, char *prefix,
		t_spec *spec)
{
	unsigned int	nbrlen;
	unsigned int	result;

	nbrlen = ft_nbrlen(nbr, base);
	if (!nbr && spec->got_precision && spec->precision == 0)
		result = 0;
	else if (spec->got_precision)
		result = ft_max(nbrlen, spec->precision);
	else
		result = nbrlen;
	if (spec->force_prefix && prefix != NULL && nbr != 0)
		result += ft_strlen(prefix);
	return (result);
}
