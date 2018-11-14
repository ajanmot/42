/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_wchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:56:13 by ajanmot           #+#    #+#             */
/*   Updated: 2017/11/30 18:56:15 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

ssize_t			ft_handle_wchar(char **format, va_list *args, t_spec *spec)
{
	wchar_t		c;
	unsigned	c_len;

	(void)format;
	c = (wchar_t)va_arg(*args, int);
	if (c <= 0x7F)
		c_len = 1;
	else if (c <= 0x7FF)
		c_len = 2;
	else if (c <= 0xFFFF)
		c_len = 3;
	else if (c <= 0x10FFFF)
		c_len = 4;
	else
		c_len = 0;
	if (spec->got_width && !spec->right_pad)
		ft_width_pad(c_len, spec->width, spec->zeroes_pad ? '0' : ' ');
	ft_putwchar(c);
	if (spec->got_width && spec->right_pad)
		ft_width_pad(c_len, spec->width, spec->zeroes_pad ? '0' : ' ');
	return (spec->got_width ? ft_max(c_len, spec->width) : (int)c_len);
}
