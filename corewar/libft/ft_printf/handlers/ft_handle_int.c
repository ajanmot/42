/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:58:24 by ajanmot           #+#    #+#             */
/*   Updated: 2017/11/30 18:58:25 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

ssize_t			ft_handle_int(char **format, va_list *args, t_spec *spec)
{
	intmax_t	nbr;
	char		*prefix;

	(void)format;
	if (spec->got_precision)
		spec->zeroes_pad = 0;
	nbr = ft_va_to_signed(args, spec);
	if (nbr < 0 || spec->force_sign || spec->blank_sign)
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			prefix = "-";
		}
		else if (spec->force_sign)
			prefix = "+";
		else if (spec->blank_sign)
			prefix = " ";
		else
			prefix = "";
		return (ft_nbr_forceprefix(nbr, "0123456789", spec, prefix));
	}
	else
		return (ft_handle_uint(nbr, spec, "0123456789", NULL));
}
