/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshara <bshara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:18:58 by bshara            #+#    #+#             */
/*   Updated: 2019/04/23 18:24:36 by bshara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*s;
	char	*ret;

	if (size == MAX_SIZE)
		return (NULL);
	if (!(s = malloc((size + 1) * sizeof(char))))
		return (NULL);
	ret = s;
	while (size)
	{
		*s = '\0';
		s++;
		size--;
	}
	*s = '\0';
	return (ret);
}
