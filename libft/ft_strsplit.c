/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshara <bshara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:55:00 by bshara            #+#    #+#             */
/*   Updated: 2019/04/25 17:55:43 by bshara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	c_words(char const *s, char c)
{
	int		i;
	int		status;

	i = 0;
	status = 0;
	while (*s != '\0')
	{
		if (status == 0)
		{
			if (*s != c)
			{
				status = 1;
				i++;
			}
			s++;
		}
		else if (status == 1)
		{
			if (*s == c)
				status = 0;
			s++;
		}
	}
	return (i);
}

static int	c_len(char const *s, char c)
{
	int		i;

	i = 0;
	while ((s[i] != c) && (s[i] != '\0'))
		i++;
	return (i);
}

static char	**ft_deltab(char **tab, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	char	**ret;
	int		nb_words;

	if (s == NULL)
		return (NULL);
	nb_words = c_words(s, c);
	if (!(ret = malloc(sizeof(char *) * (nb_words + 1))))
		return (NULL);
	i = 0;
	while (nb_words--)
	{
		while ((*s == c) && (*s != '\0'))
			s++;
		if (!(ret[i] = ft_strsub(s, 0, c_len(s, c))))
			return (ft_deltab(ret, i));
		s += c_len(s, c);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
