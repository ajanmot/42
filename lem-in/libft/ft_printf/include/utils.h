/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:55:10 by ajanmot           #+#    #+#             */
/*   Updated: 2017/11/30 18:55:51 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "include.h"

unsigned int	ft_calc_nbrlen(uintmax_t nbr, char *base, char *prefix,
		t_spec *spec);
ssize_t			ft_nbr_forceprefix(uintmax_t nbr, char *base, t_spec *spec,
		char *prefix);
intmax_t		ft_va_to_signed(va_list *args, t_spec *spec);
uintmax_t		ft_va_to_unsigned(va_list *args, t_spec *spec);
void			ft_width_pad(int len, int width, char pad);

#endif
