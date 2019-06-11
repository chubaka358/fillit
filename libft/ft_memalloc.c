/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:55:01 by bshara            #+#    #+#             */
/*   Updated: 2019/04/10 19:55:43 by bshara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*s;
	size_t	i;

	s = malloc(size * sizeof(unsigned char));
	if (!s)
		return (NULL);
	i = 0;
	while (i < size)
	{
		((unsigned char*)s)[i] = 0;
		i++;
	}
	return (s);
}
