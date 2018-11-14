NAME = libft.a

SRC = ft_atoi.c \
	  ft_bzero.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_itoa.c \
	  ft_memalloc.c \
	  ft_memccpy.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memdel.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_putchar.c \
	  ft_putchar_fd.c \
	  ft_putendl.c \
	  ft_putendl_fd.c \
	  ft_putnbr.c \
	  ft_putnbr_fd.c \
	  ft_putstr.c \
	  ft_putstr_fd.c \
	  ft_strcat.c \
	  ft_strchr.c \
	  ft_strclr.c \
	  ft_strcmp.c \
	  ft_strcpy.c \
	  ft_strdel.c \
	  ft_strdup.c \
	  ft_strequ.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strjoin.c \
	  ft_strlcat.c \
	  ft_strlen.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strncat.c \
	  ft_strncmp.c \
	  ft_strncpy.c \
	  ft_strnequ.c \
	  ft_strnew.c \
	  ft_strnstr.c \
	  ft_strrchr.c \
	  ft_strsplit.c \
	  ft_strstr.c \
	  ft_strsub.c \
	  ft_strtrim.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_lstnew.c \
	  ft_lstdelone.c \
	  ft_lstdel.c \
	  ft_lstadd.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  ft_lstpushback.c \
	  ft_lstpushfront.c \
	  ft_lstpushparams.c \
	  ft_lstreverse.c \
	  ft_lstsort.c  \
	  ft_ptrswap.c \
	  get_next_line.c \
	  ft_min.c \
	  ft_max.c \
	  ft_nbrlen.c \
	  ft_strnlen.c \
	  ft_putwchar.c \
	  ft_putnbr_base.c \
	  ft_putnstr.c \
	  ft_strisdigit.c \
	  ft_strclen.c \
	  ft_strisnumber.c \
	  ft_lst_remove_item.c \
	  ft_calloc.c \
	  ft_atol.c \
	  ft_is_number.c \
	  ft_str_char_count.c \

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

%.o : %.c


BIN = $(SRC:.c=.o)

HEADERS = ./libft.h \
		  ./get_next_line.h

CFLAGS = -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME): $(BIN) $(HEADERS)
	@make -C ft_printf
	@ar rc $(NAME) $(BIN)
	@ranlib $(NAME)

%.o: %.c $(HEADERS)
	@printf "$(LOG_U)$(WARN_C)[%s]$(STOP_C) Compiling : %s              \
		\n" "$(word $(INCR), $(CHARS))" "$@"
	@$(eval INCR = $(shell echo $$(($(INCR) % 8 + 1))))
	@gcc -o $@ -c $< -I ./ $(CFLAGS)

clean:
	@make clean -C ft_printf
	@rm -f $(BIN)

fclean: clean
	@make fclean -C ft_printf
	@printf "$(ERROR_C)[RM]$(STOP_C) $(SILENT_C)%s$(STOP_C) Deleted\n" "$(NAME)"
	@printf "\n"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
