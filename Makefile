FLAGS = -g -Wall -Wextra -Werror
LIB = libft/
FUNC = fillit.c
FUNC_O = $(FUNC:.c=.o)
EXEC = fillit

all:
	clang $(FLAGS) -I $(LIB) -L $(LIB) -lft $(FUNC) -o $(EXEC)

clean:
	/bin/rm -Rf $(FUNC_O)

fclean: clean
	/bin/rm -Rf $(EXEC)

re: fclean all