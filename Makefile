FLAGS = -g -Wall -Wextra -Werror
LIB = libft/
FUNC = fillit.c
FUNC_O = $(FUNC:.c=.o)
NAME = fillit

all: $(NAME)
	@gcc -c $(FLAGS) $(FUNC)
	@gcc -I $(LIB) -L $(LIB) -lft $(FUNC_O) -o $(EXEC)

$(NAME): $(OBJ)
	make -C libft
	gcc -L ./libft -lft

clean:
	@/bin/rm -Rf $(FUNC_O)

fclean: clean
	@/bin/rm -Rf $(EXEC)

re: fclean all