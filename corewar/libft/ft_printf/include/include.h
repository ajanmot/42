/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:55:57 by ajanmot           #+#    #+#             */
/*   Updated: 2018/01/04 22:49:25 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H
# include "../../libft.h"
# include <stdarg.h>
# include <stdint.h>

int					ft_printf(const char *format, ...);
typedef struct		s_spec
{
	int				force_prefix : 1;
	int				zeroes_pad : 1;
	int				right_pad : 1;
	int				force_sign : 1;
	int				blank_sign : 1;
	int				got_width : 1;
	int				got_precision : 1;
	unsigned int	width;
	unsigned int	precision;
	enum	{
		none,
		hh,
		h,
		ll,
		l,
		j,
		z
	}				length;
}					t_spec;
typedef ssize_t		(*t_ptr_func) (char **, va_list *, t_spec *);
ssize_t				(*g_ft_get_func(char c)) (char **, va_list *, t_spec *);
char				*parse_flags(char **format, t_spec *spec);
char				*parse_width(char **format, va_list *args, t_spec *spec);
char				*parse_precision(char **format, va_list *args,
		t_spec *spec);
char				*parse_length(char **format, t_spec *spec);
ssize_t				ft_handle_binary(char **format, va_list *args,
		t_spec *spec);
ssize_t				ft_handle_hex(char **format, va_list *args, t_spec *spec);
ssize_t				ft_handle_unsigned(char **format, va_list *args,
		t_spec *spec);
ssize_t				ft_handle_null(char **format, va_list *args, t_spec *spec);
ssize_t				ft_handle_str(char **format, va_list *args, t_spec *spec);
ssize_t				ft_handle_ptr(char **format, va_list *args, t_spec *spec);
ssize_t				ft_handle_char(char **format, va_list *args, t_spec *spec);
ssize_t				ft_handle_wchar(char **format, va_list *args, t_spec *spec);
ssize_t				ft_handle_wstr(char **format, va_list *args, t_spec *spec);
ssize_t				ft_handle_int(char **format, va_list *args, t_spec *spec);
ssize_t				ft_handle_uint(uintmax_t nrb, t_spec *spec, char *base,
		char *prefix);
ssize_t				ft_handle_octal(char **format, va_list *args, t_spec *spec);
ssize_t				ft_handle_escape(char **format, va_list *args,
		t_spec *spec);
ssize_t				ft_handle_long(char **format, va_list *args, t_spec *spec);
unsigned int		ft_calc_nbrlen(uintmax_t nbr, char *base, char *prefix,
		t_spec *spec);
ssize_t				ft_nbr_forceprefix(uintmax_t nbr, char *base, t_spec *spec,
		char *prefix);
intmax_t			ft_va_to_signed(va_list *args, t_spec *spec);
uintmax_t			ft_va_to_unsigned(va_list *args, t_spec *spec);
void				ft_width_pad(int len, int width, char pad);

#endif
