/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chubaka358 <chubaka358@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:54:51 by bshara            #+#    #+#             */
/*   Updated: 2019/05/03 15:07:14 by chubaka358       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (len == 0)
	{
		if ((ret = malloc(1)))
		{
			ret[0] = '\0';
			return (ret);
		}
		return (NULL);
	}
	if ((start + len - 1 >= ft_strlen(s)) || (!(ret = malloc(len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		ret[i] = s[start];
		i++;
		start++;
	}
	ret[i] = '\0';
	return (ret);
}
