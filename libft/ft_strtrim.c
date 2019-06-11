/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:26:26 by bshara            #+#    #+#             */
/*   Updated: 2019/04/12 14:26:29 by bshara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	find_end(const char *s, int i)
{
	while ((s[i] == ' ') || (s[i] == '\t') || (s[i] == '\n'))
	{
		i--;
	}
	return (i);
}

static int	find_start(const char *s)
{
	int		i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	return (i);
}

char		*ft_strtrim(char const *s)
{
	char	*ret;
	int		i;
	int		start;
	int		end;

	if (s == NULL)
		return (NULL);
	start = find_start(s);
	end = find_end(s, ft_strlen(s) - 1);
	if (end == -1)
	{
		if (!(ret = malloc(sizeof(char) * 1)))
			return (NULL);
		ret[0] = '\0';
		return (ret);
	}
	if (!(ret = malloc(sizeof(char) * (end - start + 2))))
		return (NULL);
	i = 0;
	while (s[start] != '\0' && start <= end)
		ret[i++] = s[start++];
	ret[i] = '\0';
	return (ret);
}
