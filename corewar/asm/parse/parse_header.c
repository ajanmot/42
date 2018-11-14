/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 19:16:26 by tkeynes           #+#    #+#             */
/*   Updated: 2018/04/12 11:00:36 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

char		*char_by_char(t_file *file, char *str, char *head)
{
	char	c;
	int		i;
	char	*tmp;

	if (!(tmp = ft_calloc(COMMENT_LENGTH + 1)))
		ft_error_asm("Error calloc\n", file, 0);
	ft_strcat(tmp, str);
	i = ft_strlen(str);
	tmp[i++] = '\n';
	while (read(file->fd_s, &c, 1) && c != '"' && i != COMMENT_LENGTH)
	{
		tmp[i] = c;
		i++;
	}
	if (c == '"')
		tmp[i] = c;
	ft_free(head);
	if (i == COMMENT_LENGTH)
	{
		ft_free(tmp);
		return (0);
	}
	return (tmp);
}

void		get_name(t_file *file, char *str)
{
	char	*head;

	if (!(str = ft_strsanitize(str, file, 0)) || *(ft_strstr(str,
NAME_CMD_STRING) + ft_strlen(NAME_CMD_STRING)) != ' ')
		ft_error_asm("Erreur parsing name header\n", file, 0);
	head = str;
	if (!(str = ft_strstr(str, " ")) || *(str + 1) != '"')
		ft_error_asm("nom de champion invalide\n", file, 0);
	if (*str && *(str + 1))
		str += 2;
	if (str[ft_strlen(str) - 1] != 34 && *str != 34)
	{
		if (!(str = char_by_char(file, str, head)))
			ft_error_asm("Taille du nom du champion trop longue -\n", file, 0);
		head = str;
	}
	str[ft_strlen(str) - 1] = 0;
	if (file->header->is_set_name || ft_strlen(str) > PROG_NAME_LENGTH)
		ft_error_asm("Error: champion name - length\n", file, 0);
	ft_strcpy(file->header->prog_name, str);
	file->header->is_set_name += 1;
	ft_free(head);
}

void		get_comment(t_file *file, char *str)
{
	char	*head;

	if (!(str = ft_strsanitize(str, file, 0)) || *(ft_strstr(str,
COMMENT_CMD_STRING) + ft_strlen(COMMENT_CMD_STRING)) != ' ')
		ft_error_asm("Erreur parsing comment header\n", file, 0);
	head = str;
	if (!(str = ft_strstr(str, " ")) || *(str + 1) != '"')
		ft_error_asm("nom de champion invalide\n", file, 0);
	if (*str && *(str + 1))
		str += 2;
	if (*str == '\0' || (str[ft_strlen(str) - 1] != 34 && *str != 34))
	{
		if (!(str = char_by_char(file, str, head)))
			ft_error_asm("Taille du comment champion trop longue\n", file, 0);
		head = str;
	}
	str[ft_strlen(str) - 1] = 0;
	if (file->header->is_set_comment || ft_strlen(str) > COMMENT_LENGTH)
		ft_error_asm("Error: champion comment - length\n", file, 0);
	ft_strcpy(file->header->comment, str);
	file->header->is_set_comment += 1;
	if (head)
		ft_free(head);
}

void		parse_header(t_file *file, int ret)
{
	char	*line;
	char	*tmp;
	char	*new;

	while ((!file->header->is_set_name || !file->header->is_set_comment) &&
			(ret = get_next_line(file->fd_s, &line, 0)))
	{
		if (ret <= 0)
			ft_error_asm("Error on oppening file", file, 0);
		file->current_line++;
		if (!(new = ft_strtrim(line)))
			ft_error_asm("Error on trim", file, 0);
		ft_free(line);
		if (*new == COMMENT_CHAR || *new == '\0' || is_spaces(new))
			ft_free(new);
		else if ((tmp = ft_strstr(new, NAME_CMD_STRING)) && tmp == new)
			get_name(file, tmp);
		else if ((tmp = ft_strstr(new, COMMENT_CMD_STRING)) && tmp == new)
			get_comment(file, tmp);
		else
			ft_error_asm("ERROR PARSE HEADER -", file, 0);
	}
	if (!file->header->is_set_name || !file->header->is_set_comment || ft_strchr
(file->header->prog_name, '"') || ft_strchr(file->header->comment, '"'))
		ft_error_asm("Veuillez entrer un nom ou un commentaire\n", file, 0);
}
