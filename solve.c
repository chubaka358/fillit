#include "fillit.h"

t_data *stack[128];
int tos = 0;
static t_list *src;

void push(int i, t_map *map)
{
	stack[tos]->shift = i;
	stack[tos]->map = map;
	tos++;
}

t_data	*pop(void)
{
	tos--;
	if (tos < 0)
		return (NULL);
	return(stack[tos]);
}

int	place_figure(t_list *list, unsigned long long figure, t_map *map, int shift)
{
	unsigned long long	tmp_map;
	t_data				*data;

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
		shift = calc_shift(shift, list, map);
		if (shift == -1)
		{
			list = list->prev;
			data = pop();
			shift = calc_shift(data->shift, list, data->map);
			place_figure(list, *((unsigned long long *)list->content), data->map, data->shift);
		}
		place_figure(list, *((unsigned long long *)list->content), map, shift);
	}
	else
	{
		push(shift, map);
		map->chart |= figure;
		if (map->chart >= map->max_size)
		{
			pop();
			return (-1);
		}
		map_str(map, figure);
		list = list->next;
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
	unsigned long	i;
	unsigned long	size;
	unsigned long	width;
	t_list			*iter;

	i = 0;
	size = 2;
	iter = list;
	while (list != NULL)
	{
		i++;
		list = list->next;
	}
	i *= 4;
	while (size * size < i)
		size++;
	while (iter != NULL)
	{
		width = (iter->rem / 4) + 1;
		if (size < iter->content_size)
			size = iter->content_size;
		if (size < width)
			size = width;
		iter = iter->next;
	}
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