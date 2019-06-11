/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascending.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshara <bshara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 15:11:14 by bshara            #+#    #+#             */
/*   Updated: 2019/04/25 15:14:59 by bshara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isascending(int *arr, int len)
{
	int	i;
	int	local_max;

	if (arr == NULL || len == 0)
		return (0);
	local_max = arr[0];
	i = 1;
	while (i < len)
	{
		if (arr[i] >= local_max)
			local_max = arr[i];
		else
			return (0);
		i++;
	}
	return (1);
}
