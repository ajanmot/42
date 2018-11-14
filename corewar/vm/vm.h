/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 22:53:25 by pgerbaud          #+#    #+#             */
/*   Updated: 2018/03/31 02:21:12 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H
# include "../libft/libft.h"
# include "../both/op.h"

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include <limits.h>

# define OPTION_DUMP 1
# define OPTION_DUMP_V 2
# define OPTION_ID_PLAYER 3
# define OPTION_ID_V 4
# define OPTION_FILE_PLAYER 5
# define OPTION_VERBOSE 6
# define OPTION_VERB_V 7
# define V_CYCLE 1
# define V_OP 2
# define V_DEATH 4
# define V_CTD 8

typedef unsigned char	t_memory_space[MEM_SIZE];

typedef unsigned int	t_register;

typedef unsigned char	*t_pc;

typedef int				t_carry;

typedef struct			s_process
{
	int					pid;
	struct s_player		*player;
	t_register			reg[REG_NUMBER + 1];
	t_pc				pc;
	t_carry				carry;
	int					is_alive;
	t_list				*list_op;
	int					wait;
	int					wait_alive;
	int					wait_fork;
	int					last_live;
}						t_process;

typedef struct			s_player
{
	int					id;
	char				name[PROG_NAME_LENGTH + 1];
	char				comment[COMMENT_LENGTH + 1];
	char				*file;
	int					is_alive;
	unsigned int		size;
}						t_player;

typedef struct			s_param
{
	int					type;
	int					value;
}						t_param;

typedef struct			s_operation
{
	int					id;
	int					cycle_left;
	t_process			*process;
	t_param				*param;
	int					n_param;
}						t_operation;

typedef struct			s_vm
{
	int					cycle_to_die;
	int					max_cycle;
	int					nbr_cycle;
	int					nbr_last_cycletodie_change;
	t_player			*winner;
	t_list				*list_players;
	t_list				*list_process;
	t_memory_space		memory_space;
	int					total_cycle;
	int					pid;
	int					param_v;
	int					param_c;
	int					param_d;
	int					param_ctd;
}						t_vm;

void					(*g_get_op_function(unsigned char id))(t_vm*,
		t_process*);

/*
**	OPERATION
*/
void					op_load(t_vm *vm, t_process *process);
void					op_alive(t_vm *vm, t_process *process);
void					op_store(t_vm *vm, t_process *process);
void					op_addition(t_vm *vm, t_process *process);
void					op_substraction(t_vm *vm, t_process *process);
void					op_and(t_vm *vm, t_process *process);
void					op_or(t_vm *vm, t_process *process);
void					op_xor(t_vm *vm, t_process *process);
void					op_jump(t_vm *vm, t_process *process);
void					op_load_index(t_vm *vm, t_process *process);
void					op_store_index(t_vm *vm, t_process *process);
void					op_fork(t_vm *vm, t_process *process);
void					op_long_load(t_vm *vm, t_process *process);
void					op_long_load_index(t_vm *vm, t_process *process);
void					op_long_fork(t_vm *vm, t_process *process);
void					op_aff(t_vm *vm, t_process *process);

/*
**	OPERATION_UTILS
*/
int						get_value_param(t_vm *vm, t_process *proc, t_pc pc,
						t_param a);
int						get_value_param_mod(t_vm *vm, t_process *proc, t_pc p,
						t_param a);
t_pc					get_adress_index(t_vm *vm, t_pc pc, short index, int m);
t_param					get_param_w_type(t_vm *vm, t_process *proc, int type,
						int s);
t_param					get_param(t_vm *vm, t_process *process,
						unsigned char *b, int s);
int						arg_type(unsigned char bin_code);
void					memcpy_cuted_form_vm(void *dst, t_vm *v, t_pc p, int s);
void					memcpy_cuted_to_vm(void *src, t_vm *vm, t_pc pc, int s);
int						get_value_from_vm(t_vm *vm, t_pc pc, int size);

/*
**	QUIT
*/
void					end_game(t_vm *vm);
void					end_dump(t_vm *vm);

/*
**	PARSE
*/
t_vm					parse_arg(int argc, char**argv);
int						magic_valid(unsigned char magic[4]);

/*
**	PLAYER
*/
void					add_player(t_list**list_players, int id);
void					add_player_file(t_list**list_players, char *file);
int						get_n_player(t_list *list_players);
void					load_players(t_vm *vm);
void					load_player(t_vm *vm, t_player *player, int n_player);

/*
**	PLAYER_ID
*/
t_player				*get_player_by_id(t_vm *vm, int id);
t_player				*get_player_by_id_(t_list *list_players, int id);
int						generate_player_id(t_list *list_players);

/*
**	PLAYER_PARSE
*/
void					parse_player_name(t_player *player, int fd);
void					parse_player_comment(t_player *player, int fd);
void					check_error_player(t_vm *vm, t_player *p, int n, int f);

/*
**	PROCESS
*/
void					add_process(t_vm *vm, t_player *player);
void					add_process_fork(t_vm *vm, t_pc pc, t_process *src);
t_process				init_process();

/*
** CYCLE
*/
void					kill_process(t_list**process, int pid);
void					check_process_alive(t_list**process, t_list *c, int cr,
						t_vm *vm);
int						alive_count(t_vm *vm);
void					check_cycletodie(t_vm *vm, t_list *current);
void					exec_cycle(t_vm *vm);

/*
** CHECK
*/
int						check_bin_code(unsigned char code, int op);
void					check_players_alive(t_vm *vm, t_list**process);

/*
**	DUMP
*/
void					dump_memory(t_vm *vm);
void					dump_players(t_list *list_player);
void					dump_player(t_player *player);
void					dump_all_process(t_vm *vm, t_list *list_process);
void					dump_process(t_vm *vm, t_process *process);
void					dump_op_pending(t_list *list_op);
void					dump_op(t_operation *op);
void					dump_param(t_param *param);

/*
**	VM
*/
t_vm					init_vm(void);
void					increment_pc(t_vm *vm, t_pc *pc, int times);
void					decrement_pc(t_vm *vm, t_pc *pc, int times);
void					increment_pc_bin_code(t_vm *v, t_pc *p, unsigned char c,
						int m);
int						bigendian(unsigned char *array, int nb_octet);

/*
**	FREE STRUCTS
*/
void					free_op(void *proc, size_t size);
void					free_all(t_vm *vm);
void					error_parsing(char *message);
int						get_cycle_op(int op);
void					file_error(int i, char *file, int fd);

/*
** VERBOSE
*/
void					set_verbose(t_vm *vm, int value);
void					verbose_live(t_player *player);
void					verbose_op_header(t_process *process);
void					verbose_op_live(t_process *process, int live);
void					verbose_op_load(t_process *process, int value, int reg);
void					verbose_op_store(t_process *process, int p1, int p2);
void					verbose_op_add(t_process *proc, int r1, int r2, int r3);
void					verbose_op_sub(t_process *proc, int r1, int r2, int r3);
void					verbose_op_and(t_process *proc, int p1, int p2, int r);
void					verbose_op_or(t_process *proc, int p1, int p2, int r);
void					verbose_op_xor(t_process *proc, int p1, int p2, int r);
void					verbose_op_jump(t_process *proc, short int val, int ok);
void					verbose_op_load_index(t_vm *vm, t_process *pro,
						t_pc start, int p[3]);
void					verbose_op_long_load_index(t_vm *vm, t_process *pro,
						t_pc start, int p[3]);
void					verbose_op_store_index(t_vm *vm, t_process *pro,
						t_pc start, int p[4]);
void					verbose_op_fork(t_process *process, short int jump,
						int c, int i);

#endif
