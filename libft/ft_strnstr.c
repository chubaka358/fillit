/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:56:22 by bshara            #+#    #+#             */
/*   Updated: 2019/04/10 15:56:28 by bshara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while ((haystack[i] != '\0') && (i < len))
	{
		j = i;
		k = 0;
		while ((haystack[j] == needle[k]) && (j < len) && (needle[k] != '\0'))
		{
			k++;
			j++;
		}
		if (needle[k] == '\0')
			return (&((char*)haystack)[i]);
		i++;
	}
	return (NULL);
}
