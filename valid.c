#include "fillit.h"

int	is_obs(char c1, char c2, char c3)
{
	if ((c1 == '#') && (c2 == '#') && (c3 == '#'))
		return (1);
	return (0);
}

void	ull_to_void(t_list *list, unsigned long long i, size_t len, size_t rem)
{
	free(list->content);
	list->content = NULL;
	list->content = malloc(sizeof(unsigned long long *));
	ft_memcpy(list->content, &i, 8);
	list->content_size = len;
	list->rem = rem;
}

int		is_valid_figure2(t_list *list, int i)
{
	if ((i + 10 < 19) && is_obs(S[i + 1], S[i + 5], S[i + 10]))
		ull_to_void(list, 51328, 2, 8);
	else if ((i + 5 < 19) && is_obs(S[i + 3], S[i + 4], S[i + 5]))
		ull_to_void(list, 11776, 3, 4);
	else if ((i + 11 < 19) && is_obs(S[i + 1], S[i + 6], S[i + 11]))
		ull_to_void(list, 50240, 2, 9);
	else if ((i + 5 < 19) && is_obs(S[i + 1], S[i + 2], S[i + 5]))
		ull_to_void(list, 59392, 3, 4);
	else if ((i + 11 < 19) && is_obs(S[i + 5], S[i + 10], S[i + 11]))
		ull_to_void(list, 35008, 2, 9);
	else if ((i + 6 < 19) && is_obs(S[i + 1], S[i + 5], S[i + 6]))
		ull_to_void(list, 52224, 2, 5);
	else if ((i + 5 < 19) && is_obs(S[i + 1], S[i + 4], S[i + 5]))
		ull_to_void(list, 27648, 3, 4);
	else if ((i + 11 < 19) && is_obs(S[i + 5], S[i + 6], S[i + 11]))
		ull_to_void(list, 35904, 2, 9);
	else if ((i + 7 < 19) && is_obs(S[i + 1], S[i + 6], S[i + 7]))
		ull_to_void(list, 50688, 3, 6);
	else if ((i + 9 < 19) && is_obs(S[i + 4], S[i + 5], S[i + 9]))
		ull_to_void(list, 19584, 2, 7);
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
		if ((i + 15 < 19) && is_obs(S[i + 5], S[i + 10], S[i + 15]))
			ull_to_void(list, 34952, 0, 12);
		else if ((i + 3 < 19) && is_obs(S[i + 1], S[i + 2], S[i + 3]))
			ull_to_void(list, 61440, 4, 3);
		else if ((i + 7 < 19) && is_obs(S[i + 5], S[i + 6], S[i + 7]))
			ull_to_void(list, 36352, 3, 6);
		else if ((i + 10 < 19) && is_obs(S[i + 5], S[i + 9], S[i + 10]))
			ull_to_void(list, 17600, 2, 8);
		else if ((i + 7 < 19) && is_obs(S[i + 1], S[i + 2], S[i + 7]))
			ull_to_void(list, 57856, 3, 6);
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
