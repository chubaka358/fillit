/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:33:44 by bshara            #+#    #+#             */
/*   Updated: 2019/04/10 15:33:45 by bshara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;
	int	k;

	if (*needle == '\0')
		return ((char*)haystack);
	i = 0;
	while (haystack[i] != '\0')
	{
		j = i;
		k = 0;
		while ((haystack[j] == needle[k]) && (needle[k] != '\0'))
		{
			j++;
			k++;
		}
		if (needle[k] == '\0')
			return (&((char *)haystack)[i]);
		i++;
	}
	return (NULL);
}
