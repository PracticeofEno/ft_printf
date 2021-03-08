/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_malloc_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 02:58:28 by sanghpar          #+#    #+#             */
/*   Updated: 2020/11/21 09:25:18 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*gm_c(t_fm *format)
{
	int		size;
	char	*arr;

	size = 0;
	if (1 < format->width)
		size = format->width;
	else
		size = 1;
	size++;
	arr = (char *)malloc(size * sizeof(char));
	if (!arr)
		return (0);
	ft_memset(arr, 0, size);
	return (arr);
}

char			*gm_i(t_fm *format, char *number)
{
	int		size;
	char	*arr;

	size = ft_strlen(number);
	if (size < format->width)
		size = format->width;
	if (size < format->precision)
		size = format->precision;
	size = size + 3;
	arr = (char *)malloc(size * sizeof(char));
	if (format->type == 'p' && number != 0)
	{
		arr[0] = '0';
		arr[1] = 'x';
	}
	if (!arr)
		return (0);
	ft_memset(arr, 0, size);
	return (arr);
}

static int		jump_size(const char *str)
{
	int i;
	int count;

	i = 1;
	count = 0;
	while (str[i])
	{
		if (is_type(str[i]))
		{
			count = i;
			return (count);
		}
		i++;
	}
	return (count);
}

int				result_size(char *str, t_fm *lst)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			i = i + jump_size(&str[i]);
		i++;
		count++;
	}
	count = count + all_converted_size(lst);
	return (count + 1);
}
