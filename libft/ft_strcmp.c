/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 21:44:25 by bshara            #+#    #+#             */
/*   Updated: 2019/04/05 21:53:21 by bshara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		max_len(const char *s1, const char *s2)
{
	int len1;
	int len2;

	len1 = 0;
	len2 = 0;
	while (*s1 != '\0')
	{
		len1++;
		s1++;
	}
	while (*s2 != '\0')
	{
		len2++;
		s2++;
	}
	if (len1 > len2)
		return (len1 + 1);
	else
		return (len2 + 1);
}

int				ft_strcmp(const char *s1, const char *s2)
{
	return (ft_strncmp(s1, s2, max_len(s1, s2)));
}
