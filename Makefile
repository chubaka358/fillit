FLAGS = -g -Wall -Wextra -Werror
LIB = libft/
FUNC = fillit.c
FUNC_O = $(FUNC:.c=.o)
EXEC = fillit

all:
	@gcc -c $(FLAGS) $(FUNC)
	@gcc -I $(LIB) -L $(LIB) -lft $(FUNC_O) -o $(EXEC)

$(EXEC): all

clean:
	@/bin/rm -Rf $(FUNC_O)

fclean: clean
	@/bin/rm -Rf $(EXEC)

re: fclean all