/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:56:32 by ajanmot           #+#    #+#             */
/*   Updated: 2017/11/30 18:56:33 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

ssize_t			ft_handle_str(char **format, va_list *args, t_spec *spec)
{
	char		*str;
	size_t		strlen;

	if (spec->length == l)
		return (ft_handle_wstr(format, args, spec));
	str = va_arg(*args, char*);
	if (str == NULL)
		str = "(null)";
	strlen = spec->got_precision ?
		ft_strnlen(str, spec->precision) : ft_strlen(str);
	if (spec->got_width && !spec->right_pad)
		ft_width_pad(strlen, spec->width, spec->zeroes_pad ? '0' : ' ');
	ft_putnstr(str, strlen);
	if (spec->got_width && spec->right_pad)
		ft_width_pad(strlen, spec->width, ' ');
	return (spec->got_width ? (size_t)(ft_max(strlen, spec->width)) : strlen);
}
