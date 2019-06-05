#include "fillit.h"

void	place_figure(t_list *list, unsigned long long figure, t_map *map, int shift)
{
	if (list == NULL)
		return ;
	figure >>= shift;
	map->chart &= figure;
	if (map->chart != 0)
	{
		map->chart = 0;
		if (((shift + list->content_size - 1) % map->border == map->border - 1) && \
			(shift + list->content_size + list->rem < map->border * map->border))
			shift += list->content_size;
		else if (shift + 1 + list->rem < map->border * map->border)
			shift++;
		place_figure(list, figure, map, shift);
	}
	else
	{
		map->chart |= figure;
		place_figure(list->next, *((unsigned long long *)list->content), map, 0);
	}
}

char	*solve_help(t_list *list, t_map *map)
{
	int shift;

	shift = 0;
	if (list == NULL)
		return (NULL);
	place_figure(list, *((unsigned long long *)list->content), map, shift);
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