/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenuntil.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshara <bshara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 19:42:06 by bshara            #+#    #+#             */
/*   Updated: 2019/05/07 16:26:47 by bshara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_lenuntil(char *s, char c)
{
	ssize_t i;
	int		was_occured;

	i = 0;
	was_occured = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			was_occured = 1;
			break ;
		}
		i++;
	}
	if (!was_occured)
		return (-1);
	return (i);
}
