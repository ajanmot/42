/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 18:06:13 by tkeynes           #+#    #+#             */
/*   Updated: 2018/03/30 18:06:39 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"
#include "../../both/op.h"

t_file		*ft_init_file(void)
{
	t_file *new_file;

	if (!(new_file = (t_file *)ft_calloc(sizeof(t_file))))
		ft_error_asm("Erreur d'allocation mémoire\n", 0, 0);
	if (!(new_file->header = (t_header *)ft_calloc(sizeof(t_header))))
		ft_bzero(new_file->header, sizeof(t_header));
	new_file->header->prog_size = 19;
	new_file->header->is_set_comment = 0;
	new_file->header->is_set_name = 0;
	new_file->header->magic = COREWAR_EXEC_MAGIC;
	new_file->instructions = 0;
	new_file->fd_s = 0;
	new_file->label = 0;
	new_file->current_line = 0;
	return (new_file);
}

void		ft_handle_file(t_file *file, char *path)
{
	char *tmp;

	file->path_s = path;
	if (((tmp = ft_strstr(path, ".s")) == 0) || *(tmp + 2))
		ft_error_asm("Veuillez entrer un fichier possedant l'extension .s\n",
file, 0);
	if ((file->fd_s = open(path, O_RDONLY)) == -1)
		ft_error_asm("Erreur lors de l'ouverture du fichier\n", file, 0);
	if ((file->path_cor = ft_strnew(ft_strlen(path) + 2)) == 0)
		ft_error_asm("Erreur d'allocation mémoire\n", file, tmp);
	file->path_cor = ft_strncpy(file->path_cor, path, tmp - path);
	ft_strcat(file->path_cor, ".cor");
}
