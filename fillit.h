#ifndef FILLIT_H

# define FILLIT_H

# include "./libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# define S ((char*)list->content)
# define I ((unsigned long long)list->content)
# include "stdio.h"


typedef struct	s_fig
{
	unsigned long long str1;
	unsigned long long str2;
	unsigned long long str3;
	unsigned long long str4;
}				t_fig;

typedef struct	s_map
{
	unsigned long long	max_size;
	unsigned long long	border;
	unsigned long long	chart;
	char 				*map;
	char				letter;
}				t_map;

t_list		*is_valid_figure(t_list *list);
int			is_buf_valid(char *BUF);
void		solve(t_list *list);
void		lstaddend(t_list *alst, t_list *new);
t_map		*map_init(t_map *map, unsigned long long border);
void		map_str(t_map *map, unsigned long long figure);
t_list		*to_start(t_list *list);
t_list		*list_init(t_list *list, t_map *map);
t_fig		*fig_init(unsigned long long s1, unsigned long long s2, unsigned long long s3, unsigned long long s4);

#endif