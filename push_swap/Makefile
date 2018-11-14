# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/02 01:49:19 by ajanmot           #+#    #+#              #
#    Updated: 2017/12/12 14:21:19 by ajanmot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_NAME = checker

P_NAME = push_swap

LL_SRCS_DIR = linked_list

CFLAGS += -Wall -Wextra -Werror

INCLUDES_PATH = includes/ libft/

CFLAGS += $(foreach d, $(INCLUDES_PATH), -I$d)

C_FILES = checker.c

P_FILES = push_swap.c \
	  select_sort.c \
	  utils.c \
	  pre_sort.c \
	  handle_spec.c \
      quick_sort.c \
	  utils_quick_sort.c

LL_FILES = ft_rotate.c \
					ft_rotate_reverse.c \
					ft_swap.c \
					ft_push.c \
					ft_list_push_params.c \
					ft_create_elem.c \
					ft_arg_to_list.c \
					ft_rotate_no_print.c \
					ft_rv_nop.c \
					ft_swap_no_print.c \
					ft_push_no_print.c \
					ft_is_sort.c \
					ft_is_valid.c \
					utils_list.c

C_DIR = srcs/checker

P_DIR = srcs/push_swap

LL_DIR = srcs/linked_list

C_SRCS = $(addprefix $(C_DIR)/, $(C_FILES))

P_SRCS = $(addprefix $(P_DIR)/, $(P_FILES))

LL_SRCS = $(addprefix $(LL_DIR)/, $(LL_FILES))

LIBFT_A = libft/libft.a

all: $(C_NAME) $(P_NAME)

$(C_NAME): $(C_SRCS) $(LL_SRCS)
	gcc $(CFLAGS) -o $(C_NAME) $(C_SRCS) $(LL_SRCS) $(LIBFT_A)

$(P_NAME): $(P_SRCS) $(LL_SRCS)
	gcc $(CFLAGS) -o $(P_NAME) $(P_SRCS) $(LL_SRCS) $(LIBFT_A)

fclean :
	rm -rf $(C_NAME) $(P_NAME)

re : fclean all
