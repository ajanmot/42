# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajanmot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/05 19:26:15 by ajanmot           #+#    #+#              #
#    Updated: 2018/01/05 19:26:18 by ajanmot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC = main.c \
			parser.c \
			solver.c \
			ft_error.c \
			ft_handle_room.c \
			ft_print.c \
			ft_handle_link.c \
			ft_utils.c \
			ft_valids.c \
			ft_last_check.c \
			ft_dijkstra.c \
			ft_free.c \
			ft_handle_file.c \
			ft_find_way.c \
			ft_handle_way.c

OBJ = $(SRC:.c=.o)

HEADERS = includes

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compilation de la libft !"
	@make -C libft
	gcc $(CFLAGS) -o $(NAME) $(OBJ) -I $(HEADERS) libft/libft.a libft/ft_printf/libftprintf.a

%.o: %.c
	gcc $(CFLAGS) -c $<

clean:
	@make clean -C libft
	rm -f $(OBJ)

fclean: clean
	@make fclean -C libft	
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
