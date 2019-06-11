/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 20:53:32 by bshara            #+#    #+#             */
/*   Updated: 2019/04/05 18:24:05 by bshara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	int		found;

	i = 0;
	found = 0;
	while (i < n)
	{
		if (((unsigned char*)src)[i] != (unsigned char)c)
			((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
		else
		{
			((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
			found = 1;
			break ;
		}
		i++;
	}
	if (found == 1)
		return (&dst[i + 1]);
	else
		return (NULL);
}
