#include "fillit.h"

unsigned long long	tetramine_formation(unsigned long long tmp1, unsigned long long tmp2, unsigned long long tmp3, unsigned long long tmp4)
{
	unsigned long long ret;

	ret = 0;
	ret = tmp1 | tmp2 | tmp3 | tmp4;
	return (ret);
}

t_fig	*fig_init(unsigned long long s1, unsigned long long s2, unsigned long long s3, unsigned long long s4)
{
	t_fig	*fig;
	

	
	fig = malloc(sizeof(t_fig));
	
	fig->str1 = s1;
	fig->str2 = s2;
	fig->str3 = s3;
	fig->str4 = s4;
	return(fig);
}

unsigned long long	init_llu(t_fig	*fig, unsigned long long border)
{
	unsigned long long tmp1;
	unsigned long long tmp2;
	unsigned long long tmp3;
	unsigned long long tmp4;

	if (border == 3)
	tmp1 = (fig->str1) << border * 3;
	tmp2 = (fig->str2) << border * 2;
	tmp3 = (fig->str3) << border;
	tmp4 = fig->str4;
	if (border < 4)
	{
		tmp1 = tmp1 >> (4 - border);
		tmp2 = tmp2 >> (4 - border);
		tmp3 = tmp3 >> (4 - border);
		tmp4 = tmp4 >> (4 - border);
	}
	return (tetramine_formation(tmp1, tmp2, tmp3, tmp4));
}

t_list		*list_init(t_list *list, t_map *map)
{
	t_list	*ret;
	int 	i;
	unsigned long long value;
	unsigned long long *addr;

	i = 0;
	addr = malloc(sizeof(unsigned long long));
	ret = malloc(sizeof(t_list));
	while (list != NULL)
	{
		if (i == 0)
		{
			value = init_llu((t_fig*)(list->content), map->border);
			addr = &value;
			ret = ft_lstnew(addr, sizeof(unsigned long long));
		}
		else
		{
			value = init_llu((t_fig*)(list->content), map->border);
			addr = &value;
			lstaddend(ret, ft_lstnew(addr, sizeof(unsigned long long)));
		}
		i++;
		list = list->next;
	}
	return (ret);
}