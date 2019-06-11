/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshara <bshara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 15:11:24 by bshara            #+#    #+#             */
/*   Updated: 2019/04/25 15:14:25 by bshara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_replace(char *str, char orig, char to)
{
	char	*ret;

	if (str == NULL)
		return (NULL);
	ret = str;
	while (*str != '\0')
	{
		if (*str == orig)
			*str = to;
		str++;
	}
	return (ret);
}
