/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:56:20 by ajanmot           #+#    #+#             */
/*   Updated: 2017/11/30 18:56:22 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

ssize_t			ft_handle_unsigned(char **format, va_list *args, t_spec *spec)
{
	uintmax_t	nbr;

	(void)format;
	nbr = ft_va_to_unsigned(args, spec);
	return (ft_handle_uint(nbr, spec, "0123456789", NULL));
}
