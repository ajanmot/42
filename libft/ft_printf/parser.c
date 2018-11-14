/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:53:39 by ajanmot           #+#    #+#             */
/*   Updated: 2017/11/30 18:53:40 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/include.h"
#include <stdio.h>

char		*parse_flags(char **format, t_spec *spec)
{
	char	*flag;

	if (**format == '\0')
		return (NULL);
	if (!(flag = ft_strchr("#0-+ ", **format)))
		return (*format);
	else
	{
		if (*flag == '#')
			spec->force_prefix = 1;
		if (*flag == '0')
			spec->zeroes_pad = 1;
		if (*flag == '-')
			spec->right_pad = 1;
		if (*flag == '+')
			spec->force_sign = 1;
		if (*flag == ' ')
			spec->blank_sign = 1;
		if (spec->right_pad)
			spec->zeroes_pad = 0;
		(*format)++;
		return (parse_flags(format, spec));
	}
}

char		*parse_width(char **format, va_list *args, t_spec *spec)
{
	int		width;

	if (**format == '*')
	{
		(*format)++;
		width = va_arg(*args, int);
		if (width < 0)
			spec->right_pad = 1;
		spec->width = width < 0 ? -width : width;
		spec->got_width = 1;
	}
	if (ft_isdigit(**format))
	{
		spec->width = 0;
		while (ft_isdigit(**format))
			spec->width = spec->width * 10 + (*(*format)++ - '0');
		spec->got_width = 1;
	}
	if (**format == '*' || ft_isdigit(**format))
		return (parse_width(format, args, spec));
	return (*format);
}

char		*parse_precision(char **format, va_list *args, t_spec *spec)
{
	int		prec;

	if (**format == '.')
	{
		(*format)++;
		if (**format == '*')
		{
			(*format)++;
			if ((prec = va_arg(*args, int)) >= 0)
			{
				spec->got_precision = 1;
				spec->precision = prec;
			}
			return (*format);
		}
		else
		{
			spec->precision = 0;
			while (ft_isdigit(**format))
				spec->precision = spec->precision * 10 + (*(*format)++ - '0');
			spec->got_precision = 1;
			return (*format);
		}
	}
	return (*format);
}

void		single_atributes(char **format, t_spec *spec)
{
	if (**format == 'h' || **format == 'l' || **format == 'j' ||
			**format == 'z')
	{
		if (**format == 'h')
			spec->length = h;
		else if (**format == 'l')
			spec->length = l;
		else if (**format == 'j')
			spec->length = j;
		else if (**format == 'z')
			spec->length = z;
		(*format)++;
	}
}

char		*parse_length(char **format, t_spec *spec)
{
	int		i;

	i = 0;
	while (*((*format) + i) && ft_strchr("hljz", *((*format) + i)))
		i++;
	if (i > 2)
	{
		spec->length = **format;
		(*format) += i;
		return (*format);
	}
	if (**format == 'h' && *(*format + 1) == 'h')
	{
		spec->length = hh;
		(*format) += 2;
	}
	else if (**format == 'l' && *(*format + 1) == 'l')
	{
		spec->length = ll;
		(*format) += 2;
	}
	single_atributes(format, spec);
	while (**format && ft_strchr("hljz", **format))
		(*format)++;
	return (*format);
}
