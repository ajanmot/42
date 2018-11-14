/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 19:15:35 by tkeynes           #+#    #+#             */
/*   Updated: 2018/03/30 19:16:20 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

void		check_last_char_new_line(t_file *file)
{
	char	buffer[2];
	int		fd;
	int		ret_read;

	fd = open((const char*)file->path_s, O_RDONLY, S_IRUSR);
	if (fd == -1)
		ft_error_asm("Erreur\n", file, 0);
	while ((ret_read = read(fd, buffer, 1)) && fd != -1)
		buffer[ret_read] = '\0';
	close(fd);
	if (*buffer != 10 && !is_spaces(buffer))
		ft_error_asm("No new line at end of file\n", file, 0);
}

void		parse_file(t_file *file)
{
	char *line;
	char **fresh;

	parse_header(file, 0);
	ft_get_labels(file);
	while (get_next_line(file->fd_s, &line, 0))
	{
		file->current_line++;
		if (!(line = ft_strsanitize(line, file, 0)))
			ft_error_asm("Erreur d'allocation mémoire\n", file, 0);
		if (!line)
			continue ;
		if (!*line)
		{
			ft_free(line);
			continue ;
		}
		if (!(fresh = ft_strsplit(line, ' ')))
			ft_error_asm("Erreur d'allocation mémoire\n", file, line);
		ft_convert_asm(file, fresh, line);
		ft_free(line);
	}
}
