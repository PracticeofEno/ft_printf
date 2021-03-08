/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_string_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:24:44 by sanghpar          #+#    #+#             */
/*   Updated: 2020/11/11 19:38:13 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fill_width(char *arr, int start_index, int size, char c)
{
	while (size > 0)
	{
		arr[start_index] = c;
		start_index++;
		size--;
	}
	return (start_index);
}

int	fill_precision(char *arr, int start_index, int precision_size)
{
	while (precision_size > 0)
	{
		arr[start_index] = '0';
		start_index++;
		precision_size--;
	}
	return (start_index);
}

int	get_precision_size(t_fm *format, char *number)
{
	int k;

	k = 0;
	if (format->precision == 0 && format->dot == 0)
	{
		if (*number == '-')
			k = ft_strlen(number) - 1;
		else
			k = ft_strlen(number);
	}
	return (k);
}

int	fill_content(char *arr, int start_index, char *content)
{
	int i;

	i = 0;
	while (content[i])
	{
		arr[start_index] = content[i];
		start_index++;
		i++;
	}
	return (start_index);
}
