/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:57:46 by ajanmot           #+#    #+#             */
/*   Updated: 2017/11/30 18:57:47 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

ssize_t				ft_handle_ptr(char **format, va_list *args, t_spec *spec)
{
	char			*base;
	uintmax_t		result;

	(void)format;
	spec->length = z;
	if (spec->precision)
		spec->zeroes_pad = 0;
	base = "0123456789abcdef";
	result = ft_va_to_unsigned(args, spec);
	return (ft_nbr_forceprefix(result, base, spec, "0x"));
}
