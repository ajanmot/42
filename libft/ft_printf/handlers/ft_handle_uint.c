/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:56:25 by ajanmot           #+#    #+#             */
/*   Updated: 2017/11/30 18:56:26 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

static void			ft_putnbrbp(uintmax_t nbr, t_spec *spec, char *base,
		unsigned int nbrlen)
{
	if (spec->got_precision)
	{
		ft_width_pad(nbrlen, spec->precision, base[0]);
	}
	if (!nbr && spec->got_precision && spec->precision == 0)
		return ;
	ft_putnbr_base(nbr, base);
}

void				check_conflict(t_spec *spec, unsigned int nbrlen,
		char *prefix)
{
	if (spec->got_width && !spec->right_pad && spec->zeroes_pad)
	{
		if (spec->got_precision)
			spec->precision = ft_max(spec->width, spec->precision);
		else
		{
			if (spec->force_prefix)
				spec->width -= ft_strlen(prefix);
			spec->precision = ft_max(spec->width, nbrlen);
		}
		spec->got_precision = 1;
		spec->got_width = 0;
	}
}

ssize_t				ft_handle_uint(uintmax_t nbr, t_spec *spec, char *base,
		char *prefix)
{
	unsigned int	nbrlen;
	unsigned int	result_len;

	if (spec->got_precision)
		spec->zeroes_pad = 0;
	nbrlen = ft_nbrlen(nbr, base);
	check_conflict(spec, nbrlen, prefix);
	result_len = ft_calc_nbrlen(nbr, base, prefix, spec);
	if (spec->got_width && !spec->right_pad)
		ft_width_pad(result_len, spec->width, ' ');
	if (spec->force_prefix && prefix && nbr)
		ft_putstr(prefix);
	ft_putnbrbp(nbr, spec, base, nbrlen);
	if (spec->got_width && spec->right_pad)
		ft_width_pad(result_len, spec->width, ' ');
	return (spec->got_width ? ft_max(result_len, spec->width)
	: (int)result_len);
}
