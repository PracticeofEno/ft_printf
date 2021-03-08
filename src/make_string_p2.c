/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_string_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 02:49:56 by sanghpar          #+#    #+#             */
/*   Updated: 2020/11/21 09:32:23 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	fc(char *arr, int start_index, char *content)
{
	int i;

	i = 0;
	while (content[i])
	{
		arr[start_index] = ft_tolower(content[i]);
		start_index++;
		i++;
	}
	return (start_index);
}

static void	fill_left(char *arr, char *number, t_fm *format)
{
	int i;
	int num_length;

	i = 2;
	num_length = ft_strlen(number);
	if (format->width < num_length)
		format->width = num_length;
	i = fc(arr, i, number);
	i = fill_width(arr, i, (format->width - i), ' ');
	arr[i] = 0x00;
}

static void	fill_right(char *arr, char *number, t_fm *format)
{
	int i;
	int num_length;

	i = 2;
	num_length = ft_strlen(number);
	if (format->width < num_length)
		format->width = num_length;
	i = fill_width(arr, i, (format->width - num_length), ' ');
	i = fc(arr, i, number);
	arr[i] = 0x00;
}

char		*make_string_p(t_fm *format, va_list *ap)
{
	long long	tmp;
	char		*arr;
	char		*number;

	setting_option(format, format->type, ap);
	tmp = (long long)va_arg(*ap, void*);
	if (tmp == 0 && format->dot == 1)
		return (ft_strdup("0x"));
	else if (tmp == 0)
		return (ft_strdup("0x0"));
	else
		number = ft_itoa_x(tmp);
	arr = gm_i(format, number);
	if (format->minus == 1)
	{
		fill_left(arr, number, format);
	}
	else
	{
		fill_right(arr, number, format);
	}
	free_buffer(&number);
	return (arr);
}
