/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 21:26:42 by ajanmot           #+#    #+#             */
/*   Updated: 2018/03/30 23:29:09 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H
# include "../../libft/libft.h"
# include "../../libft/ft_printf/include/ft_printf.h"
# include "../../both/op.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct				s_operande{
	char					*initial;
	unsigned char			*final;
	int						type;
	int						n;
	int						is_label;
	int						byte_size;
}							t_operande;

typedef struct				s_label
{
	struct s_label			*next;
	char					*name;
}							t_label;

typedef struct				s_instruction
{
	char					*raw_instruction;
	char					**raw_operandes;
	char					**labels;
	t_op					*op;
	char					ocp;
	t_operande				**args;
	int						nb_octets;
	int						is_ready;
	unsigned char			*final_op_code;
}							t_instruction;

typedef struct				s_file
{
	int						fd_s;
	char					*path_cor;
	char					*path_s;
	t_header				*header;
	t_label					*label;
	t_list					*instructions;
	int						current_line;
}							t_file;

void						parse_header(t_file *file, int ret);

void						parse_file(t_file *file);
void						ft_get_labels(t_file *file);
void						check_last_char_new_line(t_file *file);

int							ft_is_well_formated(t_file *file, char **tab,
int status);
int							ft_convert_asm(t_file *file, char **tab,
char *string);

int							ft_detect_type(t_file *file, char *operande);
t_operande					**new_operande_struct(t_file *file,
t_instruction *instruction);
t_operande					*new_operande(t_file *file, char *operande,
t_instruction *instruction);
unsigned char				*generate_reg_operande(t_file *file,
t_operande *operande);
unsigned char				*generate_dir_operande(t_file *file,
t_operande *operande, t_instruction *instruction);
unsigned char				*generate_ind_operande(t_file *file,
t_operande *operande);
unsigned char				*generate_operande(t_file *file,
t_operande *operande, t_instruction *instruction);
void						generate_label_operandes(t_file *file,
t_list *instructions);

char						**ft_add_label(t_file *file, char **tab_lab,
char *label);
int							ft_add_label_to_list(t_file *file, char *label);
int							ft_is_label_valid(char *label);
int							ft_is_label_exist(t_file *file, char *label);
void						ft_get_labels(t_file *file);

int							ft_is_op(char **tab, t_file *file);

unsigned char				generate_ocp(t_file *file,
t_instruction *instruction, int counter);

void						ft_free_file(t_file *file);
int							ft_free_tab(char **tab, int status);
void						ft_free_label(t_label *label);
void						ft_free_all_instruction(t_list	*instruction);
void						ft_free_instruction(t_instruction	*instruction);

int							ft_error_asm(char *str, t_file *file,
void *to_free);
char						*ft_strsanitize(char *str, t_file *file, int size);

t_instruction				*new_instruction(t_file *file,
char *raw_instruction, char **splitted_instruction, char **labels);
int							get_nb_bytes_instruction(
t_instruction *instruction);
t_list						*get_ins_lab(t_list *list, char *label_to_find);
int							get_position_of_instruction(t_list *list,
t_instruction *to_find);
int							weight_beetween_instruction(t_list *first,
t_list *second);
unsigned char				*get_memory_gap_labels(t_file *file,
t_list *begin_list, t_list *current, t_operande *label_to_find);

void						write_file(t_file *file);

unsigned char				binary_to_byte(char *string);
unsigned int				rev_indian(unsigned int n);
unsigned char				*int_to_bytes(t_file *file, long n,
int nb_bytes);
unsigned char				reverse_bits(unsigned char b);

int							is_spaces(char *str);

t_file						*ft_init_file(void);
void						ft_handle_file(t_file *file, char *path);

int							ft_free(void *ptr);

#endif
