/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 07:05:37 by sanghpar          #+#    #+#             */
/*   Updated: 2020/11/06 17:05:10 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_overflow_int(int sign, unsigned int u_num)
{
	if (sign == 1 && u_num > 0x7fffffff)
		return (-1);
	else if (sign == -1 && u_num > 0x80000000)
		return (0);
	return (1);
}

char		*ft_atoi(char *str, int *va)
{
	int				sign;
	int				res;

	while (*str == '\t' || *str == '\v' || *str == '\n'
			|| *str == '\r' || *str == '\f' || *str == ' ')
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	*va = 0;
	while (ft_isdigit(*str))
	{
		*va = (*va * 10) + (*str - '0');
		if ((res = ft_check_overflow_int(sign, *va)) != 1)
			return (0);
		str++;
	}
	*va = *va * sign;
	return (str);
}
