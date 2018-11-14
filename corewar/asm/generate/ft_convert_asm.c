/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_asm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 17:30:47 by tkeynes           #+#    #+#             */
/*   Updated: 2018/04/12 10:50:40 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"
#include "../../both/op.h"

int				ft_is_well_formated(t_file *file, char **tab, int status)
{
	int			i;
	char		**params;

	i = 0;
	while (tab[i])
		i++;
	if (i != 2)
		return (0);
	if (!(params = ft_strsplit(tab[1], SEPARATOR_CHAR)))
		ft_error_asm("Erreur d'allocation memoire\n", file, 0);
	i = 0;
	while (params[i])
		i++;
	if (i != g_op_tab[status].nb_params && !ft_free_tab(params, 0))
		return (0);
	i = 0;
	while (i < g_op_tab[status].nb_params)
	{
		if ((!(ft_detect_type(file, params[i])) || !(ft_detect_type(file,
params[i]) & g_op_tab[status].param_types[i])) && !ft_free_tab(params, 0))
			return (0);
		i++;
	}
	ft_free_tab(params, 0);
	return (1);
}

int				ft_analyze_label(char **tab)
{
	char *ret;

	if ((ret = ft_strchr(*tab, LABEL_CHAR)))
		if (((*tab)[ft_strlen(*tab) - 1] != LABEL_CHAR) ||
				(!ft_is_label_valid(*tab)))
			return (-1);
	return (ret ? 1 : 0);
}

int				push_ins(t_file *file, char **tab, char *line, char **labels)
{
	t_instruction		*var;

	if (!tab || !*tab)
		return (0);
	if (!ft_is_well_formated(file, tab, ft_is_op(tab, file)))
	{
		ft_printf(C_RED"--> %s\n"C_NONE, line);
		ft_error_asm("Erreur de formatage (well formated)\n", file, line);
	}
	var = new_instruction(file, line, tab, labels);
	ft_lstpushback(&(file->instructions), &var);
	return (0);
}

int				push_free_ins(char *string, int first_ret, int ret, char **tab)
{
	if (string == 0 && first_ret != ret)
		ft_free_tab(tab - 1, 0);
	else
		ft_free_tab(tab, 0);
	return (0);
}

int				ft_convert_asm(t_file *file, char **tab, char *line)
{
	int					a;
	char				**b;
	char				*c;
	int					d;

	if (((b = 0) == 0) && (!tab || !*tab))
		return (0);
	d = ft_analyze_label(tab);
	while ((a = ft_analyze_label(tab)))
	{
		if (((c = 0) == 0) && ((*(tab + 1) && ft_analyze_label(tab + 1) == 1) ||
a == -1 || (b = ft_add_label(file, b, *tab)) == 0))
			ft_error_asm("Erreur convert_asm\n", file, 0);
		if (!(*(++tab)))
		{
			while (!c || *c == '\0' || *c == COMMENT_CHAR || is_spaces(c))
				if (!ft_free(c) || !get_next_line(file->fd_s, &c, 0) || !(c =
ft_strsanitize(c, file, 0)))
					ft_error_asm("Convert_asm - Label at end alone\n", file, 0);
			if (ft_free_tab(tab - 1, 0) == 1 || !(tab = ft_strsplit(c, ' ')))
				ft_error_asm("Erreur d'allocation mémoire\n", file, c);
			ft_free(c);
		}
	}
	return ((push_ins(file, tab, line, b) + push_free_ins(c, d, a, tab)) * 0);
}
