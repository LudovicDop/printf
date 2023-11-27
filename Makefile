MAKEFLAGS += --silent
tools = ft_printf.c ./tools/ft_c.c ./tools/ft_int.c ./tools/ft_string.c ./tools/ft_u.c ./tools/ft_p.c ./tools/ft_x.c ./tools/ft_x2.c ./tools/ft_modulo.c
CC = gcc -Wall -Werror -Wextra
OBJ = $(libft:.c=.o)
OBJ_TOOLS = $(tools:.c=.o)
NAME = libftprintf.a

all : $(NAME)

.c.o :
	$(CC) -c $< -o $(<:.c=.o)
$(NAME) : $(OBJ) $(OBJ_TOOLS)
	echo "Creation en cours..."
	make -C libft/
	mv libft/libft.a .
	mv libft.a $(NAME)
	ar rcs $@ $(OBJ) $(OBJ_TOOLS)
	echo "Succes"
clean :
	make clean -C libft/ 
	rm -rf $(OBJ) $(OBJ_TOOLS)
fclean : clean
	make fclean -C libft/
	rm -rf $(NAME)
re : fclean all $(NAME)
