#include "fillit.h"

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