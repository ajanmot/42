# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/30 18:53:33 by ajanmot           #+#    #+#              #
#    Updated: 2018/01/04 22:55:34 by ajanmot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c \
      parser.c

UTILS_NAME = ft_calc_nbrlen.c \
      ft_nbr_forceprefix.c \
      ft_va_to_signed.c \
      ft_va_to_unsigned.c \
      ft_width_pad.c

HANDLERS_NAME =  ft_handle_binary.c \
      ft_handle_wstr.c \
      ft_handle_wchar.c \
      ft_handle_unsigned.c \
      ft_handle_uint.c \
      ft_handle_str.c \
      ft_handle_ptr.c \
      ft_handle_octal.c \
      ft_handle_null.c \
      ft_handle_long.c \
      ft_handle_int.c \
      ft_handle_hex.c \
      ft_handle_escape.c \
      ft_handle_char.c \
      type_to_func_array.c

LIBFT_NAME = ft_max.c \
	     ft_min.c \
	     ft_nbrlen.c \
	     ft_putnstr.c \
	     ft_strlen.c \
	     ft_putstr.c \
	     ft_putchar.c \
	     ft_putnwstr.c \
	     ft_putwchar.c \
	     ft_memalloc.c \
	     ft_isdigit.c \
	     ft_strchr.c \
		ft_bzero.c \
		ft_tolower.c \
		ft_strnlen.c \
		ft_putnbr_base.c

HANDL_DIR = handlers

UTILS_DIR = utils

LIBFT_DIR = ..

HANDLERS = $(addprefix $(HANDL_DIR)/, $(HANDLERS_NAME))

UTILS = $(addprefix $(UTILS_DIR)/, $(UTILS_NAME))

LIBFT = $(addprefix $(LIBFT_DIR)/, $(LIBFT_NAME))

BIN = $(SRC:.c=.o) $(UTILS_NAME:.c=.o) $(HANDLERS_NAME:.c=.o) $(LIBFT_NAME:.c=.o)

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	gcc -c $(CFLAGS) $(SRC) $(HANDLERS) $(UTILS) $(LIBFT)
	ar rc $(NAME) $(BIN)
	ranlib $(NAME)

clean:
	rm -f $(BIN)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
