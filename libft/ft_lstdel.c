/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshara <bshara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 20:13:56 by bshara            #+#    #+#             */
/*   Updated: 2019/04/23 15:19:57 by bshara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*ptr;
	t_list	*tmp;

	if (alst != NULL && del != NULL)
	{
		ptr = *alst;
		while (ptr != NULL)
		{
			tmp = ptr;
			ft_lstdelone(&ptr, del);
			ptr = tmp->next;
		}
		*alst = NULL;
	}
}
