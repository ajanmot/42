/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_octal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:58:02 by ajanmot           #+#    #+#             */
/*   Updated: 2017/11/30 18:58:06 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

ssize_t	ft_handle_octal(char **format, va_list *args, t_spec *spec)
{
	uintmax_t	nbr;

	(void)format;
	nbr = ft_va_to_unsigned(args, spec);
	if (spec->force_prefix && nbr == 0 &&
			spec->got_precision && spec->precision == 0)
	{
		if (spec->got_width && !spec->right_pad)
			ft_width_pad(1, spec->width, spec->zeroes_pad ? '0' : ' ');
		ft_putstr("0");
		if (spec->got_width && spec->right_pad)
			ft_width_pad(1, spec->width, ' ');
		return (spec->got_width ? ft_max(spec->width, 1) : 1);
	}
	if (spec->got_precision && spec->force_prefix)
		spec->precision -= 1;
	return (ft_handle_uint(nbr, spec, "01234567", "0"));
}
