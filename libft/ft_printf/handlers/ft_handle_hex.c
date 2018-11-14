/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:58:31 by ajanmot           #+#    #+#             */
/*   Updated: 2017/11/30 18:58:32 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

ssize_t	ft_handle_hex(char **format, va_list *args, t_spec *spec)
{
	uintmax_t	nbr;

	nbr = ft_va_to_unsigned(args, spec);
	if (**format == 'X')
		return (ft_handle_uint(nbr, spec, "0123456789ABCDEF", "0X"));
	else
		return (ft_handle_uint(nbr, spec, "0123456789abcdef", "0x"));
}
