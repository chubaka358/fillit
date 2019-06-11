/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 13:45:02 by bshara            #+#    #+#             */
/*   Updated: 2019/04/12 13:45:04 by bshara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		i;

	if ((s1 == NULL) || (s2 == NULL))
		return (NULL);
	if (!(ret = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (*s1 != '\0')
	{
		ret[i] = *s1;
		s1++;
		i++;
	}
	while (*s2 != '\0')
	{
		ret[i] = *s2;
		s2++;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
