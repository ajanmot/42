/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_null.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:58:09 by ajanmot           #+#    #+#             */
/*   Updated: 2017/11/30 18:58:10 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

ssize_t	ft_handle_null(char **format, va_list *args, t_spec *spec)
{
	(void)args;
	if (spec->got_width && !spec->right_pad)
		ft_width_pad(1, spec->width, spec->zeroes_pad ? '0' : ' ');
	ft_putchar(**format);
	if (spec->got_width && spec->right_pad)
		ft_width_pad(1, spec->width, ' ');
	return (spec->got_width ? ft_max(spec->width, 1) : 1);
}
