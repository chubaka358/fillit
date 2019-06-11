/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshara <bshara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:21:31 by bshara            #+#    #+#             */
/*   Updated: 2019/04/17 18:07:41 by bshara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strrev(char *s, int len)
{
	int		i;
	char	*ret;

	i = 0;
	if (!(ret = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (--len >= 0)
	{
		ret[i] = s[len];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

static int	ft_nlen(int n)
{
	int		i;

	i = 0;
	if (n != 0)
	{
		while (n != 0)
		{
			n /= 10;
			i++;
		}
	}
	else
		i = 1;
	return (i);
}

char		*ft_itoa(int n)
{
	char	*ret;
	int		i;
	int		status;

	i = 0;
	status = 0;
	if (n < 0)
		status = 1;
	if (!(ret = malloc(sizeof(char) * (ft_nlen(n) + 1))))
		return (NULL);
	i = 0;
	if (n != 0)
		while (n != 0)
		{
			ret[i] = (n % 10) < 0 ? -(n % 10) + '0' : (n % 10) + '0';
			n /= 10;
			i++;
		}
	else
		ret[i++] = 0 + '0';
	ret[i] = '\0';
	return (status ? ft_strjoin("-", ft_strrev(ret, i)) : ft_strrev(ret, i));
}
