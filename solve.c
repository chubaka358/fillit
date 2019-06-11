#include "fillit.h"

int stack[128];
int tos = 0;
static t_list *src;

void push(int i)
{
	stack[tos] = i;
	tos++;
}

int	pop(void)
{
	tos--;
	if (tos < 0)
		return (-1);
	return(stack[tos]);
}

int	place_figure(t_list *list, unsigned long long figure, t_map *map, int shift)
{
	unsigned long long tmp_map;

	figure >>= shift;
	tmp_map = map->chart;
	tmp_map &= figure;
	if (figure == 0)
	{
		map_init(map, ++(map->border));
		place_figure(list_init(src, map), *((unsigned long long *) ((list_init(src, map))->content)), map, 0);
	}
	if (tmp_map != 0)
	{
		if (((shift + list->content_size - 1) % map->border == map->border - 1) && \
		(shift + list->content_size + list->rem < map->border * map->border))
			shift += list->content_size;
		else if (shift + 1 + list->rem < map->border * map->border)
			shift++;
		else
		{
			list = list->prev;
			place_figure(list, *((unsigned long long *)list->content), map, pop());
		}
		place_figure(list, figure, map, shift);
	}
	else
	{
		map->chart |= figure;
		if (map->chart > map->max_size)
			return (-1);
		map_str(map, figure);
		list = list->next;
		push(shift);
		if (list == NULL)
			return (0);
		place_figure(list, *((unsigned long long *)list->content), map, 0);
	}
	return (1);
}

void	solve_help(t_list *list, t_map *map)
{
	int shift;
	int status;

	shift = 0;
	status = place_figure(list, *((unsigned long long *) list->content), map, shift);
	while (status < 0)
	{
		map_init(map, ++(map->border));
		status = place_figure(list_init(src, map), *((unsigned long long *) list->content), map, shift);
	}
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
	t_map *map;
	unsigned long long	i;

	map = malloc(sizeof(t_map));
	map_init(map, min_border(list));
	src = list;
	solve_help(list_init(src, map), map);
	i = 0;
	while(i < map->border)
	{
		write(1, map->map, map->border);
		(map->map) += (map->border);
		write(1, "\n", 1);
		i++;
	}
}