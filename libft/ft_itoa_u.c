/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 13:32:32 by sanghpar          #+#    #+#             */
/*   Updated: 2020/11/05 22:41:14 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen_u(unsigned int n)
{
	int	count;

	if (n == 0)
		return (2);
	count = 1;
	if (n < 0)
		count++;
	while (n)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

char		*ft_itoa_u(unsigned int n)
{
	char	*arr;
	int		len;

	len = ft_nbrlen_u(n);
	if (!(arr = (char *)malloc(len * sizeof(char))))
		return (NULL);
	arr[len - 1] = 0x00;
	len--;
	if (n < 0)
	{
		arr[0] = '-';
		while (len-- > 1)
		{
			arr[len] = '0' - (n % 10);
			n = n / 10;
		}
	}
	else
		while (len--)
		{
			arr[len] = '0' + (n % 10);
			n = n / 10;
		}
	return (arr);
}
