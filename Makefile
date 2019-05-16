CC=gcc
CFLAGS=-g -Wall -Wextra -Werror
DEPS=fillit.h
OBJ=fillit.o

%.o:%.c ßß$(DEPS)
	$(СС) -c -o $@ $< $(CFLAGS)

fillit: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) -L libft -lft