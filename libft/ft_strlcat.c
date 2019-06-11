/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 23:27:33 by bshara            #+#    #+#             */
/*   Updated: 2019/04/09 15:39:10 by bshara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	ft_min(size_t len1, size_t len2)
{
	if (len1 < len2)
		return (len1);
	return (len2);
}

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;

	j = 0;
	dst_len = ft_strlen(dst);
	i = dst_len;
	if (size == 0)
		return (ft_strlen(src));
	while ((i < size - 1) && (src[j] != '\0'))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (ft_strlen(src) + ft_min(dst_len, size));
}
