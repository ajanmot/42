
NAME = libft.a
FLAGS = -Wall -Werror -Wextra
HEADERS = ./includes/
SRC = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c
OBJFILES = ft_putchar.o ft_putstr.o ft_strcmp.o ft_swap.o ft_strlen.o


all :
	gcc $(FLAGS) -c $(SRC) -I $(HEADERS)
	ar rc $(NAME) $(OBJFILES)
	ranlib $(NAME)

clean :
	/bin/rm -f $(OBJFILES)

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all
