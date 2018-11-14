/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_va_to_signed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:54:22 by ajanmot           #+#    #+#             */
/*   Updated: 2017/11/30 18:54:24 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

intmax_t		ft_va_to_signed(va_list *args, t_spec *spec)
{
	intmax_t	nbr;

	nbr = va_arg(*args, intmax_t);
	if (spec->length == hh)
		nbr = (char)nbr;
	else if (spec->length == h)
		nbr = (short int)nbr;
	else if (spec->length == l)
		nbr = (long int)nbr;
	else if (spec->length == ll)
		nbr = (long long int)nbr;
	else if (spec->length == j)
		nbr = (intmax_t)nbr;
	else if (spec->length == z)
		nbr = (size_t)nbr;
	else
		nbr = (int)nbr;
	return (nbr);
}
