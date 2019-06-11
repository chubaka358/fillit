#include "fillit.h"

int stack[128];
int tos = 0;

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
void	place_figure(t_list *list, unsigned long long figure, t_map *map, int shift)
{
	unsigned long long tmp_map;

	if (list == NULL)
		return ;
	figure >>= shift;
	tmp_map = map->chart;
	tmp_map &= figure;
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
			place_figure(list->prev, *((unsigned long long *)list->content), map, pop());
		}
		place_figure(list, figure, map, shift);
	}
	else
	{
		map->chart |= figure;
		if (map->chart > map->max_size)
			return (-1);
		list = list->next;
		push(shift);
		place_figure(list, *((unsigned long long *)list->content), map, 0);
	}
}

void	solve_help(t_list *list, t_map *map)
{
	int shift;

	shift = 0;
	
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
	t_map *map;

	map = malloc(sizeof(t_map));
	map_init(map, min_border(list));
	solve_help(list, map);
}