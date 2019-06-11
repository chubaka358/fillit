#include "fillit.h"

void	map_init(t_map *map, unsigned long long border)
{
	map->border = border;
	map->max_size = 1;
	map->max_size <<= (map->border) * (map->border);
	map->chart = 0;
}