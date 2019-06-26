#include "fillit.h"

t_map *copy_map(t_map **map)
{
	t_map	*ret;

	ret = malloc(sizeof(t_map));
	ret->border = (*map)->border;
	ret->chart = (*map)->chart;
	ret->max_size = (*map)->max_size;
	ret->map = ft_strnew(ft_strlen((*map)->map));
	ft_strcpy(ret->map, (*map)->map);
	ret->letter = (*map)->letter;
	return (ret);
}

int     calc_shift(int shift, t_list *list, t_map *map)
{
    if (((shift + list->content_size - 1) % map->border == map->border - 1) && \
		(shift + list->content_size + list->rem < map->border * map->border))
			shift += list->content_size;
	else if (shift + 1 + list->rem < map->border * map->border)
		shift++;
    else
    {
        shift = -1;
    }
    return (shift);
}