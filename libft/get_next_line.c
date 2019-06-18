/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chubaka358 <chubaka358@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 12:08:58 by chubaka358        #+#    #+#             */
/*   Updated: 2019/05/11 14:06:17 by chubaka358       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static t_list	*ft_correct_list(t_list **curr, int fd)
{
	t_list		*tmp;

	tmp = *curr;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(curr, tmp);
	return (tmp);
}

static int		ft_new_line(char **line, t_list *curr)
{
	int			len;
	char		*tmp;

	len = 0;
	while (((char*)(curr->content))[len] != '\n' \
			&& ((char*)(curr->content))[len] != '\0')
		len++;
	if ((len == 0) && ((char *)(curr->content))[0] == '\0')
		return (0);
	*line = ft_strsub(curr->content, 0, len);
	if (((char *)(curr->content))[len] == '\0')
		tmp = ft_strnew(1);
	else
		tmp = ft_strsub(curr->content, len + 1, \
		ft_strlen(curr->content) - ft_strlen(*line) - 1);
	ft_strdel((char **)(&(curr->content)));
	curr->content = tmp;
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static t_list	*file;
	int				ret;
	t_list			*curr;
	char			*tmp;

	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	curr = ft_correct_list(&file, fd);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if (curr->content == NULL)
			curr->content = ft_strnew(1);
		tmp = ft_strjoin(curr->content, buf);
		free(curr->content);
		curr->content = tmp;
		if (ft_strchr(curr->content, '\n'))
			break ;
	}
	if (ret == -1)
		return (-1);
	if ((ret == 0) && (((char*)(curr->content))[0] == '\0'))
		return (0);
	return (ft_new_line(line, curr));
}
