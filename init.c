#include "fillit.h"

t_fig	*fig_init(unsigned long long s1, unsigned long long s2, unsigned long long s3, unsigned long long s4)
{
	t_fig	*fig;

	fig = malloc(sizeof(fig));
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
	unsigned long long ret;

	ret = 0;
	tmp1 = (fig->str1) << border * 3;
	tmp2 = (fig->str2) << border * 2;
	tmp3 = (fig->str3) << border;
	ret = tmp1 | tmp2 | tmp3 | fig->str4;
	return (ret);
}

t_list		*list_init(t_list *list, t_map *map)
{
	t_list	*ret;
	int 	i;

	i = 0;
	ret = malloc(sizeof(t_list));
	while (list != NULL)
	{
		if (i == 0)
			ret = ft_lstnew((unsigned long long *)init_llu((t_fig*)(list->content), map->border), sizeof(unsigned long long));
		else
			lstaddend(ret, ft_lstnew((unsigned long long *)init_llu((t_fig*)(list->content), map->border), sizeof(unsigned long long)));
		i++;
		list = list->next;
	}
	return (ret);
}