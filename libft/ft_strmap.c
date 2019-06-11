/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:37:49 by bshara            #+#    #+#             */
/*   Updated: 2019/04/11 18:37:50 by bshara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	char			*ret;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(ret = (char*)malloc((ft_strlen(s) + 1) * sizeof(char))))
		return (NULL);
	if ((f != NULL))
	{
		while (s[i] != '\0')
		{
			ret[i] = f(s[i]);
			i++;
		}
		ret[i] = '\0';
		return (ret);
	}
	return (NULL);
}
