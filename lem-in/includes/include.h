/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 08:13:32 by ajanmot           #+#    #+#             */
/*   Updated: 2018/01/05 20:35:15 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# include "../libft/libft.h"
# include <stdio.h>
# include <limits.h>

typedef	struct		s_link
{
	char			*from;
	char			*to;
	struct s_link	*next;
}					t_link;

typedef	struct		s_room
{
	char			*name;
	int				used;
	int				weight;
	int				is_full;
	t_link			*links;
	struct s_room	*next;
	struct s_room	*previous;
}					t_room;

typedef struct		s_file
{
	t_room			*room;
	struct s_file	*next;
}					t_file;

typedef struct		s_ways
{
	t_file			*way;
	int				ant_to_send;
	int				ant_send;
	float			coefficient;
	struct s_ways	*next;
}					t_ways;

int					ft_buffer_get_next_line(char **line, int fd, int status);

/*
**	Parser's functions
*/

int					parser(t_room **room, char ***start_end);
int					parse_links(t_room **rooms, char ***tab);
int					parse_rooms(t_room **rooms, char ***start_end);
void				ft_free_start_end(char ***start_end);
void				lem_in_error(t_room **rooms, int status);
int					ft_strisdigit(char *str);
int					ft_free_tab(char **tab, int status);
int					ft_is_info_line_valid(char *line, t_room **rooms);
char				*ft_is_comment(char *line, char ***start_end,
																t_room **rooms);
int					ft_is_ready(char ***start_end, t_room **room, char *line);
int					ft_is_linker(char *line, char ***tab, t_room **rooms);
int					ft_is_first_line_valid(void);
char				*ft_alloc_line(char *line, char ***start_end, int status
															, t_room **rooms);
int					ft_free_line_and_quit(char *line, int ret);
int					ft_check_doublons(t_room *rooms);
int					ft_unique_link(t_link *linker);

/*
**	Room's  & Links handlers
*/

t_room				*ft_new_room(char *name);
void				ft_roompushback(t_room **begin_list, t_room *new);
void				ft_link_pushback(t_room *to_link, char **tab, int status);
void				ft_print_rooms(t_room *rooms);
void				ft_print_rooms_all(t_room *rooms);
void				ft_add_room(char *line, t_room **rooms);
t_room				*get_elem(t_room **current, char *to_find);
t_link				*ft_new_link(char **tab, int status);
void				ft_free_list(t_room *room);

/*
**	File handlers
*/

void				ft_print_file(t_file *f);
t_file				*ft_new_file(t_room *to_link);
void				ft_file_pushback(t_file **file, t_room *to_link);
int					ft_is_in_file(t_file *head, t_room *to_find);
void				ft_queue(t_file **file, t_room **rooms);
int					ft_is_full(t_file *current);
void				ft_free_file(t_file *file);
void				ft_file_error(t_file *file, t_room *rooms, int status);

/*
**	Way handlers
*/

t_ways				*ft_new_ways(t_file *to_link);
void				ft_ways_push_back(t_ways **head, t_file *to_link);
int					ft_get_max_size(t_ways *head);
int					ft_get_size(t_file *elem);
void				ft_free_way(t_ways *head);

/*
**	Solver's functions
*/

void				ft_solver(t_room **rooms, char **start_end, int nb_fourmis);
void				ft_dijkstra_error(t_ways *head, t_room *rooms,
												char **start_end, int status);
void				ft_browse_way(t_file *current);
t_file				*get_shorter_way(t_file *head, char **start_end);
void				ft_backtrack_elem(t_room *elem, t_file **new);
t_file				*get_shorter_way(t_file *head, char **start_end);
void				ft_direct_path(int nom_fourmis,
											int nb_fourmis, t_file *current);
void				ft_moove_ant(t_ways *head, int nb_fourmis);
void				ft_reset_rooms(t_file *head);
t_file				*ft_handle_dijkstra(t_room **rooms, char **start_end);
#endif
