/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_binary.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:58:45 by ajanmot           #+#    #+#             */
/*   Updated: 2017/11/30 18:58:49 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

ssize_t	ft_handle_binary(char **format, va_list *args, t_spec *spec)
{
	uintmax_t	nbr;

	(void)format;
	nbr = ft_va_to_unsigned(args, spec);
	return (ft_handle_uint(nbr, spec, "01", "0b"));
}
