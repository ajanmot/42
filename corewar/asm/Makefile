# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/05 19:26:15 by ajanmot           #+#    #+#              #
#    Updated: 2018/03/31 04:20:42 by pgerbaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

BOTH =	op \

OBJECTS = ft_label \
			ft_ocp \
			ft_op \
			ft_operande \
			ft_operande_gen \
			ft_instruction \
			ft_label_gen \
            ft_file

GENERATE = ft_convert_asm \
			write_file

OTHER = ft_error \
		ft_free \
		ft_strsanitize \
		other

PARSE = parse_file \
		parse_header

BITWISE = bitwise_operations \

SRC = 	$(addprefix ../both/, $(BOTH)) \
		$(addprefix objects/, $(OBJECTS)) \
		$(addprefix generate/, $(GENERATE)) \
		$(addprefix op_func/, $(OP_FUNC)) \
		$(addprefix other/, $(OTHER)) \
		$(addprefix parse/, $(PARSE)) \
		$(addprefix bitwise/, $(BITWISE)) \
		main \

OBJ=$(addsuffix .o, $(SRC))

LIB = ../libft
INC = ./includes ../both/op.h

CFLAGS = -Wall -Werror -Wextra

# ----------- COLORS -----------
 LOG_U:= \033[A
 STOP_C:= \x1b[0m
 OK_C:= \033[0;32m
 ERROR_C:= \x1b[31;01m
 WARN_C:= \x1b[33;01m
 SILENT_C:= \x1b[29;01m
 CHARS:= / / - - \\ \\ | |
 INCR:= 1
# -------------------------------


all : $(NAME)
	@printf "\n"

%.o : %.c
	@printf "$(LOG_U)$(WARN_C)[%s]$(STOP_C) Compiling : %s             \
		\n" "$(word $(INCR), $(CHARS))" "$@"
	@$(eval INCR = $(shell echo $$(($(INCR) % 8 + 1))))
	@gcc -o $@ -c $< $(CFLAGS)

$(NAME) : $(OBJ)
	@make -C $(LIB)
	@printf "$(LOG_U)$(OK_C)[OK]$(STOP_C) Compiling done for             \
		$(SILENT_C)%s$(STOP_C)       \n\n" "$(LIB)"
	@gcc $(CLFAGS) -o $@ $^ $(CFLAGS) $(LIB)/libft.a $(LIB)/ft_printf/libftprintf.a
	@printf "$(LOG_U)$(OK_C)[OK]$(STOP_C) Compiling done for             \
		$(SILENT_C)%s$(STOP_C)       \n" "$@"
	@printf "\n"

clean :
	@make -C $(LIB) clean
	@rm -f $(OBJ)

fclean : clean
	@make -C $(LIB) fclean
	@printf "$(LOG_U)$(ERROR_C)[RM]$(STOP_C) $(SILENT_C)%s$(STOP_C) Deleted\n" "$(NAME)"
	@printf "\n"
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
