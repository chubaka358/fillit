#include "fillit.h"

void	place_figure(t_list *list, t_map *map, int shift)
{
	map->chart &= *((unsigned long long *)list->content);
	if (map->chart != 0)
	{
		map->chart = 0;
		shift++;
	}

}

char	*solve_help(t_list *list, t_map *map)
{
	int shift;

	shift = 0;
	if (list == NULL)
		return (NULL);
	place_figure(list, map, shift);
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
	unsigned long long	max_map;
	t_map *map;

	map->border = min_border(list);
	map->max_size = 1;
	map->max_size <<= (map->border) * (map->border);
	map->chart = 0;
	solve_help(list, map);
	printf("%llu", max_map);
}