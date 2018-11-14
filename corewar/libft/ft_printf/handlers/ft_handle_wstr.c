/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_wstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:56:09 by ajanmot           #+#    #+#             */
/*   Updated: 2017/11/30 18:56:10 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"
#include <stdio.h>

static size_t		ft_calc_wstrlen(wchar_t *str, int precision, size_t i)
{
	if (!*str || !precision)
		return (i);
	else if (*str <= 0x7F)
		return (ft_calc_wstrlen(str + 1, precision - 1, i + 1));
	else if (*str <= 0x7FF && precision >= 2)
		return (ft_calc_wstrlen(str + 1, precision - 2, i + 2));
	else if (*str <= 0xFFFF && precision >= 3)
		return (ft_calc_wstrlen(str + 1, precision - 3, i + 3));
	else if (*str <= 0x10FFFF && precision >= 4)
		return (ft_calc_wstrlen(str + 1, precision - 4, i + 4));
	else
		return (i);
}

static size_t		ft_wstrlen(wchar_t *str)
{
	size_t			i;

	i = 0;
	while (*str)
	{
		if (*str <= 0x7F)
			i++;
		else if (*str <= 0x7FF)
			i += 2;
		else if (*str <= 0xFFFF)
			i += 3;
		else if (*str <= 0x10FFFF)
			i += 4;
		str++;
	}
	return (i);
}

ssize_t				ft_handle_wstr(char **format, va_list *args, t_spec *spec)
{
	wchar_t			*str;
	size_t			strlen;

	(void)format;
	str = va_arg(*args, wchar_t*);
	strlen = spec->got_precision ? ft_calc_wstrlen(str, spec->precision, 0)
		: ft_wstrlen(str);
	if (spec->got_width && !spec->right_pad)
		ft_width_pad(strlen, spec->width, spec->zeroes_pad ? '0' : ' ');
	ft_putnwstr(str, strlen);
	if (spec->got_width && spec->right_pad)
		ft_width_pad(strlen, spec->width, ' ');
	return (spec->got_width ? ft_max(strlen, spec->width) : (int)strlen);
}
