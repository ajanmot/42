/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:58:40 by ajanmot           #+#    #+#             */
/*   Updated: 2017/11/30 18:58:40 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

ssize_t	ft_handle_char(char **format, va_list *args, t_spec *spec)
{
	(void)format;
	if (spec->length == l)
		return (ft_handle_wchar(format, args, spec));
	else
	{
		if (spec->got_width && !spec->right_pad)
			ft_width_pad(1, spec->width, spec->zeroes_pad ? '0' : ' ');
		ft_putchar(va_arg(*args, int));
		if (spec->got_width && spec->right_pad)
			ft_width_pad(1, spec->width, spec->zeroes_pad ? '0' : ' ');
		return (spec->got_width ? ft_max(spec->width, 1) : 1);
	}
}
