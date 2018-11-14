/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:53:25 by ajanmot           #+#    #+#             */
/*   Updated: 2017/11/30 19:33:28 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/include.h"
#include "stdio.h"

ssize_t		arg_manipulator(char **format, va_list *args, t_spec *spec)
{
	ssize_t	len;
	ssize_t	(*func)(char **, va_list *, t_spec *);

	len = 0;
	(*format)++;
	while (ft_strchr("#0-+ *hljz.123456789", **format))
	{
		if (!(**format))
			return (0);
		if (parse_flags(format, spec) == NULL)
			return (-1);
		if (parse_width(format, args, spec) == NULL)
			return (-1);
		if (parse_precision(format, args, spec) == NULL)
			return (-1);
		if (parse_length(format, spec) == NULL)
			return (-1);
	}
	if (!(**format))
		return (0);
	if (!(func = g_ft_get_func(**format)))
		func = &ft_handle_null;
	len = func(format, args, spec);
	(*format)++;
	return (len);
}

ssize_t		browse_format(const char *format, va_list *args, ssize_t len)
{
	ssize_t	ret;
	char	*start;
	t_spec	spec;

	start = (char *)format;
	while (*format)
	{
		if (*format == '%')
		{
			ft_bzero(&spec, sizeof(spec));
			ft_putnstr(start, format - start);
			if ((ret = arg_manipulator((char **)&format, args, &spec)) == -1)
				return (len);
			len += ret;
			start = (char *)format;
		}
		else
		{
			len++;
			format++;
		}
	}
	ft_putnstr(start, format - start);
	return (len);
}

int			ft_printf(const char *format, ...)
{
	va_list	args;
	ssize_t	len;

	len = 0;
	if (format)
	{
		va_start(args, format);
		len = browse_format(format, &args, len);
		va_end(args);
	}
	return (len);
}
