/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshara <bshara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:19:09 by bshara            #+#    #+#             */
/*   Updated: 2019/04/23 20:07:26 by bshara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' \
	|| c == '\r' || c == ' ')
		return (1);
	return (0);
}

static char	*ft_skip_spaces(const char *str)
{
	while (ft_isspace(*str))
		str++;
	return ((char *)str);
}

static char	*ft_skip_sign(const char *str, int *sign)
{
	if (*str == '-')
	{
		*sign = 1;
		str++;
	}
	else
	{
		*sign = 0;
		if (*str == '+')
			str++;
	}
	return ((char*)str);
}

int			ft_atoi(const char *str)
{
	unsigned long long		result;
	unsigned int			digit;
	int						sign;
	int						symb;

	symb = 0;
	result = 0;
	str = ft_skip_spaces(str);
	str = ft_skip_sign(str, &sign);
	while (1)
	{
		digit = *str - '0';
		if (digit > 9)
			break ;
		result = (result * 10) + digit;
		str++;
		symb++;
		if ((sign == 1) && result > 9223372036854775808ULL)
			return (0);
		if ((sign == 0) && result > 9223372036854775807ULL)
			return (-1);
	}
	if (sign)
		return (-(int)result);
	return ((int)result);
}
