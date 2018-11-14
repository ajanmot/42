/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 01:43:14 by ajanmot           #+#    #+#             */
/*   Updated: 2017/12/12 15:42:32 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef	struct		s_pile
{
	int				value;
	struct s_pile	*next;
}					t_pile;

t_pile				*ft_create_elem(int value);
void				ft_list_push_params(t_pile **pile, char **av);
void				recursiv_push_swap(t_pile **a, t_pile **b, t_pile *current,
	t_pile *pivot);
void				swap_a(t_pile **pile);
void				swap_b(t_pile **pile);
void				swap_both(t_pile **a, t_pile **b);
void				push_a(t_pile **a, t_pile **b);
void				push_b(t_pile **a, t_pile **b);
void				rotate_a(t_pile **a);
void				rotate_b(t_pile **b);
void				rotate_both(t_pile **a, t_pile **b);
void				rotate_rev_a(t_pile **a);
void				rotate_rev_b(t_pile **b);
void				rotate_reverse_both(t_pile **a, t_pile **b);
void				swap_a_no_print(t_pile **pile);
void				swap_b_no_print(t_pile **pile);
void				swap_both_no_print(t_pile **a, t_pile **b);
void				push_a_no_print(t_pile **a, t_pile **b);
void				push_b_no_print(t_pile **a, t_pile **b);
void				rotate_a_no_print(t_pile **a);
void				rotate_b_no_print(t_pile **b);
void				rotate_both_no_print(t_pile **a, t_pile **b);
void				rotate_rev_a_no_print(t_pile **a);
void				rotate_rev_b_no_print(t_pile **b);
void				rotate_reverse_both_no_print(t_pile **a, t_pile **b);
int					arg_to_list(int argc, char **argv, t_pile **a);
int					ft_is_valid(char **argv);
int					ft_check_doublons(t_pile *a);
int					ft_check_range(char *str);
int					ft_check_min(char *str, char *comp);
int					ft_check_max(char *str, char *comp);
int					select_sort(t_pile **a, t_pile **b);
int					move(t_pile **a, t_pile **b, char *mvt, int times);
int					ft_is_sort(t_pile *pile, t_pile *b);
int					get_second_max(t_pile *a);
int					get_size(t_pile *a);
int					get_pos_max(t_pile *a);
t_pile				*get_last(t_pile *a);
int					elementary(t_pile **a, t_pile **b, char *sign);
t_pile				*get_elem(t_pile *a, int value);
int					get_max(t_pile *a);
int					get_second_max(t_pile *a);
int					get_pos(t_pile *a, t_pile *elem);
t_pile				*get_last(t_pile *a);
int					calculate_and_move_to_top3(t_pile **a, t_pile **b,
	t_pile *to_top);
void				replace_in_tab(int to_replace, int max, int *min_pos,
	int pre_sort_nb);
void				set_min_tab(t_pile *a, int *min_pos, int pre_sort_nb);
int					pre_sort(t_pile **a, t_pile **b, int pre_sort_nb);
int					get_max_in_tab(int *min_pos, int pre_sort_nb);
int					is_in_tab(int n, int *min_pos, int pre_sort_nb);
void				size_of_3(t_pile **a);
void				less_than_6(t_pile **a, t_pile **b);
void				more_than_6(t_pile **a, t_pile **b);
t_pile				*get_previous(t_pile *a, t_pile *elem);
int					is_all_inferior(t_pile *a, t_pile *elem);
int					is_all_superior(t_pile *a, t_pile *elem);
void				ft_del(t_pile **head);

#endif
