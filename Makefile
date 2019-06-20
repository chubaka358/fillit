CC=gcc
CFLAGS=-g -Wall -Wextra -Werror
DEPS=fillit.h
OBJ=fillit.o valid.o list.o solve.o map.o init.o help.o

all: $(OBJ) fillit

%.o:%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

fillit: $(OBJ)
	make -C libft
	$(CC) -o $@ $^ $(CFLAGS) -L libft -lft

clean:
	/bin/rm -f $(OBJ)
	make clean -C libft

fclean: clean
	/bin/rm -f fillit
	make fclean -C libft

re: fclean all