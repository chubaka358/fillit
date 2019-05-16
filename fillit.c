/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshara <bshara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 21:39:04 by bshara            #+#    #+#             */
/*   Updated: 2019/05/16 22:19:07 by bshara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		is_figure(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '#')
		i++;
	if (((i + 15 < 20) && is_obs(s[i + 5], s[i + 10], s[i + 15])) || ((i + 3 \
	< 20)&& is_obs(s[i + 1], s[i + 2], s[i + 3])))
		return (1);
	if ((i + 11 < 20) && ((is_obs(s[i + 1], s[i + 6], s[i + 11])) || (is_obs(s[\
	i + 5], s[i + 10], s[i + 11])) || (is_obs(s[i + 5], s[i + 6], s[i + 11]))))
		return (1);
	if ((i + 10 < 20) && ((is_obs(s[i + 5], s[i + 9], s[i + 10])) || (is_obs(s[\
	i + 1], s[i + 5], s[i + 10]))))
		return (1);
	if (((i + 9 < 20) && is_obs(s[i + 4], s[i + 5], s[i + 9])) || ((i + 6 < 20)\
	 && is_obs(s[i + 1], s[i + 5], s[i + 6])))
		return (1);
	if ((i + 7 < 20) && ((is_obs(s[i + 5], s[i + 6], s[i + 7])) || (is_obs(s[i \
	+ 1], s[i + 2], s[i + 7])) || is_obs(s[i + 1], s[i + 6], s[i + 7])))
		return (1);
	if ((i + 5 < 20) && (is_obs(s[i + 3], s[i + 4], s[i + 5]) || (is_obs(s[i + \
	1], s[i + 2], s[i + 5])) || (is_obs(s[i + 1], s[i + 4], s[i + 5]))))
		return (1);
	return (0);
}

int     is_valid_figure(t_list *list)
{
	int is_found;

	is_found = 0;
    while (list != NULL)
    {
		if (!is_figure((char*)list->content))
			return (0);
		list = list->next;
    }
	return (1);
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

int     is_valid(int fd)
{
    char    BUF[21];
    int     ret;
    int     i;
    static t_list *list;

    i = 0;
    while ((ret = read(fd, BUF, 20)))
    {
        if (ret == -1)
            return (0);
        BUF[ret] = '\0';
        if (!is_buf_valid(BUF))
            return (0);
        if (i == 0)
            list = ft_lstnew(BUF, 21);
        else
            ft_lstadd(&list, ft_lstnew(BUF, 21));
        ret = read(fd, BUF, 1);
        if (ret != 0 && BUF[0] != '\n')
            return (0);
    }
	return (is_valid_figure(list));
}

int     main(int argc, char **argv)
{
    int     fd;

    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        if (is_valid(fd))
        {
            write(1, "correct\n", 8);
        }
        else
            write(1, "error\n", 6);
    }
    else
    {
        
    }
    return (0);
}