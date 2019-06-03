#include "fillit.h"

int	is_obs(char c1, char c2, char c3)
{
	if ((c1 == '#') && (c2 == '#') && (c3 == '#'))
		return (1);
	return (0);
}

void	ull_to_void(t_list *list, unsigned long long i)
{
	free(list->content);
	list->content = NULL;
	list->content = malloc(sizeof(unsigned long long *));
	ft_memcpy(list->content, &i, 8);
}

int		is_valid_figure2(t_list *list, int i)
{
	if ((i + 10 < 20) && is_obs(S[i + 1], S[i + 5], S[i + 10]))
		ull_to_void(list, 51328);
	else if ((i + 5 < 20) && is_obs(S[i + 3], S[i + 4], S[i + 5]))
		ull_to_void(list, 11776);
	else if ((i + 11 < 20) && is_obs(S[i + 1], S[i + 6], S[i + 11]))
		ull_to_void(list, 50240);
	else if ((i + 5 < 20) && is_obs(S[i + 1], S[i + 2], S[i + 5]))
		ull_to_void(list, 59392);
	else if ((i + 11 < 20) && is_obs(S[i + 5], S[i + 10], S[i + 11]))
		ull_to_void(list, 35008);
	else if ((i + 6 < 20) && is_obs(S[i + 1], S[i + 5], S[i + 6]))
		ull_to_void(list, 52224);
	else if ((i + 5 < 20) && is_obs(S[i + 1], S[i + 4], S[i + 5]))
		ull_to_void(list, 27648);
	else if ((i + 11 < 20) && is_obs(S[i + 5], S[i + 6], S[i + 11]))
		ull_to_void(list, 35904);
	else if ((i + 7 < 20) && is_obs(S[i + 1], S[i + 6], S[i + 7]))
		ull_to_void(list, 50688);
	else if ((i + 9 < 20) && is_obs(S[i + 4], S[i + 5], S[i + 9]))
		ull_to_void(list, 19584);
	else
		return (0);
	return (1);
}

t_list     *is_valid_figure(t_list *list)
{
	int	i;
	t_list *start;

	start = list;
	while (list != NULL)
	{
		i = 0;
		while (S[i] != '#')
			i++;
		if ((i + 15 < 20) && is_obs(S[i + 5], S[i + 10], S[i + 15]))
			ull_to_void(list, 34952);
		else if ((i + 3 < 20) && is_obs(S[i + 1], S[i + 2], S[i + 3]))
			ull_to_void(list, 61440);
		else if ((i + 7 < 20) && is_obs(S[i + 5], S[i + 6], S[i + 7]))
			ull_to_void(list, 36352);
		else if ((i + 10 < 20) && is_obs(S[i + 5], S[i + 9], S[i + 10]))
			ull_to_void(list, 17600);
		else if ((i + 7 < 20) && is_obs(S[i + 1], S[i + 2], S[i + 7]))
			ull_to_void(list, 57856);
		else if (!is_valid_figure2(list, i))
			return (NULL);
		list = list->next;
	}
	return (start);
}

int     is_buf_valid(char *BUF)
{
    int     i;
	int		obstacle;

    i = 0;
	obstacle = 0;
    while (i < 20)
    {
        if ((i % 5 == 4) && BUF[i] != '\n')
            return (0);
        else if ((i % 5 != 4) && BUF[i] != '.' && BUF[i] != '#')
            return (0);
		if (BUF[i] == '#')
			obstacle++;
        i++;
    }
	if (obstacle != 4)
		return (0);
    return (1);
}
