/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 23:07:37 by ajanmot           #+#    #+#             */
/*   Updated: 2017/11/30 18:31:11 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

t_fdlist			*ft_make_new(int fd)
{
	t_fdlist		*new;

	new = (t_fdlist *)malloc(sizeof(t_fdlist));
	new->fd = fd;
	new->b = (char *)malloc(sizeof(char));
	new->b[0] = '\0';
	new->c = 0;
	return (new);
}

t_fdlist			*ft_get_infos(int fd, t_list **head)
{
	t_list			*current;
	t_list			*prev;

	current = *head;
	if (!*head)
	{
		*head = ft_lstnew(ft_make_new(fd), sizeof(t_fdlist));
		return ((*head)->content);
	}
	while (current && ((t_fdlist *)(current->content))->fd != fd)
	{
		prev = current;
		current = current->next;
	}
	if (!current)
	{
		prev->next = ft_lstnew(ft_make_new(fd), sizeof(t_fdlist));
		return (prev->next->content);
	}
	return (current->content);
}

int					ft_read_line(int const fd, t_fdlist *cur)
{
	int				ret_read;
	char			*buffer;
	char			*tmp;

	if (!(buffer = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)))
		return (-1);
	while ((ret_read = read(fd, buffer, BUFF_SIZE)))
	{
		if (ret_read == -1)
			return (-1);
		buffer[ret_read] = '\0';
		if (!(tmp = ft_strjoin(cur->b, buffer)))
			return (-1);
		free(cur->b);
		cur->b = tmp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (ret_read);
}

int					ft_free_and_quit(t_list **head, int fd)
{
	t_list *current;
	t_list *prec;

	current = *head;
	while (current && ((t_fdlist *)current->content)->fd != fd)
	{
		prec = current;
		current = current->next;
	}
	if (((t_fdlist *)current->content)->b[((t_fdlist *)current->content)->c]
		== '\0')
	{
		if (current == *head)
			*head = current->next;
		else
			prec->next = (prec->next)->next;
		free(((t_fdlist *)current->content)->b);
		free(((t_fdlist *)current->content));
		free(current);
		current = NULL;
	}
	return (1);
}

int					get_next_line(int const fd, char **line)
{
	static t_list	*head;
	t_fdlist		*cur;
	char			*res;
	int				ret_read;

	cur = ft_get_infos(fd, &head);
	if (ft_strchr(&(cur->b[cur->c]), '\n'))
	{
		res = ft_strchr(&(cur->b[cur->c]), '\n');
		*line = ft_strsub(cur->b, cur->c, (size_t)(res - &(cur->b[cur->c])));
		cur->c += (int)(res - &(cur->b[cur->c]) + 1);
		return (1);
	}
	if ((ret_read = ft_read_line(fd, cur)) == -1)
		return (-1);
	if (!(res = ft_strchr(&(cur->b[cur->c]), '\n')))
	{
		*line = ft_strnew(ft_strlen(&(cur->b[cur->c])));
		*line = ft_strcpy(*line, &(cur->b[cur->c]));
		cur->c += ft_strlen(&(cur->b[cur->c]));
		return (!ret_read && !ft_strlen(*line) ? 0 : 1);
	}
	*line = ft_strsub(cur->b, cur->c, (size_t)(res - &(cur->b[cur->c])));
	cur->c += res - &(cur->b[cur->c]) + 1;
	return (ret_read == BUFF_SIZE ? 1 : ft_free_and_quit(&head, fd));
}
