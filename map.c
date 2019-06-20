#include "fillit.h"

t_map	*map_init(t_map *map, unsigned long long border)
{
	map->border = border;
	map->max_size = 1;
	map->max_size <<= (map->border) * (map->border);
	map->chart = 0;
	map->map = ft_strnew((map->border) * (map->border));
	map->letter = 'A';
	return(map);
}

void	map_str(t_map *map, unsigned long long figure)
{
	unsigned long long	tmp;
	unsigned long long	res;
	int 				i;

	i = (map->border * map->border) - 1;
	tmp = figure;
	while (tmp != 0 && i >= 0)
	{
		res = tmp % 2;
		if (res == 1)
			map->map[i] = map->letter;
		else if (!ft_isalpha(map->map[i]))
			map->map[i] = '.';
		i--;
		tmp /= 2;
	}
	(map->letter)++;
}

t_list	*to_start(t_list *list)
{
	while (list->prev != NULL)
		list = list->prev;
	return (list);
}

void	inc_letter(t_map *map)
{
	(map->letter)++;
}

t_list	*change_list(t_list *list, unsigned long long *addr, size_t size)
{
	t_list *ret;

	ret =  malloc(sizeof(t_list));
	ret->content = malloc(size);
	ret->content_size = list->content_size;
	ret->rem = list->rem;
	ft_memcpy(ret->content, addr, size);
	free(list->content);
	free(list);
	ret->next = NULL;
	ret->prev = NULL;
	return (ret);
}