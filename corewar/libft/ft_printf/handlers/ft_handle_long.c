/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:58:17 by ajanmot           #+#    #+#             */
/*   Updated: 2017/11/30 18:58:18 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

ssize_t	ft_handle_long(char **format, va_list *args, t_spec *spec)
{
	(void)args;
	spec->length = l;
	return (g_ft_get_func(ft_tolower(**format))(format, args, spec));
}
