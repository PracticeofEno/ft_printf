/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_h.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:36:32 by sanghpar          #+#    #+#             */
/*   Updated: 2020/11/18 00:41:17 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_nbrlen_hex(long long n)
{
	int count;

	if (n == 0)
		return (2);
	count = 1;
	if (n < 0)
		count++;
	while (n)
	{
		count++;
		n = n / 16;
	}
	return (count);
}

static void			init_value(int *len, char **hex, long long n)
{
	*len = ft_nbrlen_hex(n);
	*hex = "0123456789abcdef";
}

static void			setting_arr(char *arr, int *len)
{
	arr[*len - 1] = 0x00;
	*len = *len - 1;
}

char				*ft_itoa_x(long long n)
{
	char	*arr;
	char	*hex;
	int		len;

	init_value(&len, &hex, n);
	if (!(arr = (char *)malloc(len * sizeof(char))))
		return (NULL);
	setting_arr(arr, &len);
	if (n < 0)
	{
		arr[0] = '-';
		while (len-- > 1)
		{
			arr[len] = hex[(n % 16)];
			n = n / 16;
		}
	}
	else
		while (len--)
		{
			arr[len] = hex[(n % 16)];
			n = n / 16;
		}
	return (arr);
}
