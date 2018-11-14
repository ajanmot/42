/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_label.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 18:10:24 by tkeynes           #+#    #+#             */
/*   Updated: 2018/04/12 10:51:25 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"
#include "../../both/op.h"

int			ft_is_label_valid(char *label)
{
	int i;

	while (*label)
	{
		i = 0;
		while (LABEL_CHARS[i])
		{
			if (*label == LABEL_CHARS[i])
				break ;
			i++;
		}
		if (!LABEL_CHARS[i] && *label != LABEL_CHAR)
			return (0);
		label++;
	}
	return (1);
}

char		**ft_add_label(t_file *file, char **tab_lab, char *label)
{
	int i;

	i = 0;
	if (label && label[ft_strlen(label) - 1] != LABEL_CHAR)
		ft_error_asm("ERROR", file, 0);
	if (tab_lab)
		while (tab_lab[i])
			i++;
	i++;
	if (!tab_lab)
		if (!(tab_lab = (char **)ft_calloc(sizeof(char *))))
			ft_error_asm("ERROR", file, 0);
	if (!(tab_lab = (char **)(realloc(tab_lab, sizeof(char *) * (i + 1)))))
		i = ft_free_tab(tab_lab, 1) + ft_error_asm("ERROR", file, 0);
	if ((tab_lab[i - 1] = ft_strdup(label)) == 0)
		ft_error_asm("ERROR", file, 0);
	tab_lab[i - 1][ft_strlen(label) - 1] = '\0';
	if ((tab_lab = (char **)(realloc(tab_lab, sizeof(char *) * (i + 1)))) == 0)
		ft_error_asm("ERROR", file, tab_lab[i - 1]);
	tab_lab[i] = 0;
	return (tab_lab);
}

int			ft_add_label_to_list(t_file *file, char *label)
{
	t_label	*new_label;
	t_label *current;

	if (label[ft_strlen(label) - 1] != LABEL_CHAR)
		return (-1);
	label[ft_strlen(label) - 1] = '\0';
	if (ft_is_label_exist(file, label) || !ft_is_label_valid(label))
		return (-1);
	if (!(new_label = (t_label *)ft_calloc(sizeof(t_label))))
		return (-1);
	if (!(new_label->name = ft_strdup(label)))
		return (-1);
	new_label->next = 0;
	if (!(current = file->label))
	{
		file->label = new_label;
		return (0);
	}
	while (current->next)
	{
		if (!ft_strcmp(current->name, label))
			return (-1);
		current = current->next;
	}
	return (!(current->next = new_label));
}

int			ft_is_label_exist(t_file *file, char *label)
{
	t_label *l;

	l = file->label;
	while (l)
	{
		if (!ft_strcmp(l->name, label))
			return (1);
		l = l->next;
	}
	return (0);
}

void		ft_get_labels(t_file *file)
{
	int		tmp;
	char	*line;
	char	**tab;

	tmp = lseek(file->fd_s, 0, SEEK_CUR);
	while (get_next_line(file->fd_s, &line, 0))
	{
		if (!(line = ft_strsanitize(line, file, 0)))
			ft_error_asm("Error malloc", file, 0);
		if (!*line)
		{
			ft_free(line);
			continue ;
		}
		if (!(line = ft_strsanitize(line, file, 0)))
			ft_error_asm("Erreur d'allocation mémoire\n", file, line);
		if (!(tab = ft_strsplit(line, ' ')))
			ft_error_asm("Erreur d'allocation mémoire\n", file, line);
		if (ft_strchr(*tab, LABEL_CHAR) && ft_add_label_to_list(file, *tab) < 0)
			tmp = ft_free_tab(tab, 0) + ft_error_asm("formatage get_labels\n"
, file, line);
		ft_free(line);
		ft_free_tab(tab, 0);
	}
	lseek(file->fd_s, tmp, SEEK_SET);
}
