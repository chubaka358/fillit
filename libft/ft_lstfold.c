/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfold.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshara <bshara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 15:11:20 by bshara            #+#    #+#             */
/*   Updated: 2019/04/25 15:15:18 by bshara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstfold(int *lst, int len)
{
	int		ret;
	int		i;

	ret = 0;
	i = 0;
	if (lst == NULL)
		return (0);
	while (i < len)
	{
		ret += lst[i];
		i++;
	}
	return (ret);
}
