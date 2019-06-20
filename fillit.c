/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshara <bshara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 21:39:04 by bshara            #+#    #+#             */
/*   Updated: 2019/06/20 16:42:03 by bshara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h> //delete this

void	print_usage()
{
	write(1, "usage: cp source_file\n", 22);
}

t_list     *is_valid(int fd)
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
			lstaddend(list, ft_lstnew(BUF, 21));
        ret = read(fd, BUF, 1);
        if (ret != 0 && BUF[0] != '\n')
            return (0);
		i++;
    }
	return (is_valid_figure(list));
}

int     main(int argc, char **argv)
{
    int     fd;
	t_list	*list;

    if (argc == 2)
	{
        fd = open(argv[1], O_RDONLY);
		list = is_valid(fd);
        if (list)
        {
			solve(list);
        }
        else
            write(1, "error\n", 6);
    }
    else
        print_usage();
    return (0);
}