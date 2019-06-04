#include "fillit.h"

char	*solve_help(t_list *list, unsigned long long size)
{
	int		is_solved;

	is_solved = 0;
	if (is_solved == 1)
		return ()
}

int		min_border(t_list *list)
{
	int		i;
	int		size;

	i = 0;
	size = 2;
	while (list != NULL)
	{
		i++;
		list = list->next;
	}
	i *= 4;
	while (size * size < i)
		size++;
	return (size);
}

void	solve(t_list *list)
{
	int					border;
	int					i;
	unsigned long long	max_map;

	border = min_border(list);
	max_map = 1;
	i = 0;
	max_map <<= (border*border);
	printf("%llu", max_map);
}