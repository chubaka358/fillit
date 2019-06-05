#ifndef FILLIT_H

# define FILLIT_H

# include "./libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# define S ((char*)list->content)
# define I ((unsigned long long)list->content)
# include "stdio.h"

t_list		*is_valid_figure(t_list *list);
int			is_buf_valid(char *BUF);
void		solve(t_list *list);
void		lstaddend(t_list *alst, t_list *new);

typedef struct	s_map
{
	unsigned long long max_size;
	unsigned long long border;
	unsigned long long chart;
}				t_map;

#endif