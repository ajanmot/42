SHELL:=/bin/bash
#---------------------------------
# Progress bar defs
#--------------------------------
ifneq ($(words $(MAKECMDGOALS)),1)
.DEFAULT_GOAL = all
%:
	@$(MAKE) $@ --no-print-directory -rRf $(firstword $(MAKEFILE_LIST))
else
ifndef ECHO
T := $(shell $(MAKE) $(MAKECMDGOALS) --no-print-directory \
      -nrRf $(firstword $(MAKEFILE_LIST)) \
      ECHO="COUNTTHIS" | grep -c "COUNTTHIS")
N := x
C = $(words $N)$(eval N := x $N)
ECHO = echo -en "\r\033[K [`expr $C '*' 100 / $T`%]"
endif

#------------------
# end progress bar
#------------------

NAME		=	corewar

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror

OPERATION	=	operation.c \
                verbose.c \
                add.c \
				live.c \
                load.c \
                store.c \
                sub.c \
                and.c \
                or.c \
                xor.c \
                jump.c \
                load_index.c \
                store_index.c \
                fork.c \
                long_load.c \
                long_load_index.c \
                long_fork.c \
                aff.c

PARSING		=	parse.c \
				parse_op.c \
                parse_player.c

SRCS		=	$(addprefix operation/, $(OPERATION)) \
                $(addprefix parse/, $(PARSING)) \
				cycle.c \
				check_cycle.c \
				check_code.c \
				dump.c \
				quit.c \
				free_struct.c \
				main.c \
				op_utils.c \
				player.c \
				player_id.c \
				process.c \
				vm.c

LIB			=	../libft/libft.a ../libft/ft_printf/libftprintf.a
HEADER		= 	vm.h ../both/op.h ../libft/libft.h
DEP			= 	$(LIB) $(HEADER) Makefile

OBJS		=	$(SRCS:.c=.o)

all 		:	$(NAME)

$(NAME) 	: 	$(OBJS) $(DEP)
	@$(ECHO) "Linking ($(NAME))\n"
	@$(CC) $(FLAGS) -o $@ $(OBJS) $(LIB);
	@[ -f $(NAME) ] && echo -e "\033[32m $(NAME) DONE !\033[0m" || echo -e "\033[31mERROR\033[0m"

%.o			: %.c $(DEP)
	@$(CC) $(FLAGS) -o $@ -c $< -I./
	@$(ECHO) Compile $<

$(LIB) 		:
	@make -C ../libft/

clean 		:
	@make -C ../libft/ clean;
	@rm -rf $(OBJS);
	@rm -rf ../both/op.o
	@$(ECHO) "$(NAME) Clean done\n"

fclean 		:
	@make -C ../libft/ fclean
	@rm -rf $(OBJS);
	@rm -rf $(NAME);
	@rm -rf ../both/op.o
	@$(ECHO) "$(NAME) FClean done\n"

re 			: 	fclean
	@make

.PHONY		: 	all clean fclean re

endif
