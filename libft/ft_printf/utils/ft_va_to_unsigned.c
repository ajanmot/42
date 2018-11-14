/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_va_to_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:54:32 by ajanmot           #+#    #+#             */
/*   Updated: 2017/11/30 18:54:35 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

uintmax_t		ft_va_to_unsigned(va_list *args, t_spec *spec)
{
	uintmax_t	nbr;

	nbr = va_arg(*args, uintmax_t);
	if (spec->length == hh)
		nbr = (unsigned char)nbr;
	else if (spec->length == h)
		nbr = (unsigned short int)nbr;
	else if (spec->length == l)
		nbr = (unsigned long int)nbr;
	else if (spec->length == ll)
		nbr = (unsigned long long int)nbr;
	else if (spec->length == j)
		nbr = (uintmax_t)nbr;
	else if (spec->length == z)
		nbr = (size_t)nbr;
	else
		nbr = (unsigned int)nbr;
	return (nbr);
}
