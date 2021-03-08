/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_string_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 02:49:56 by sanghpar          #+#    #+#             */
/*   Updated: 2020/11/19 05:38:48 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	fill_precision2(char *arr, int start_index, int precision_size,
		char **number)
{
	if (**number == '-')
	{
		arr[start_index] = '-';
		(*number)++;
		precision_size++;
		start_index++;
	}
	while (precision_size > 0)
	{
		arr[start_index] = '0';
		start_index++;
		precision_size--;
	}
	return (start_index);
}

static int	fc(char *arr, int start_index, char *content,
		t_fm *format)
{
	int i;

	i = 0;
	while (content[i])
	{
		if (i >= format->precision)
			break ;
		arr[start_index] = content[i];
		start_index++;
		i++;
	}
	return (start_index);
}

static void	fill_left(char *arr, char *number, t_fm *format, int width)
{
	int i;
	int num_length;

	i = 0;
	num_length = ft_strlen(number);
	if (format->precision == 0 && format->dot == 0)
		format->precision = get_precision_size(format, number);
	i = fill_precision2(arr, i, (format->precision - num_length), &number);
	i = fc(arr, i, number, format);
	i = fill_width(arr, i, (width - i), ' ');
	arr[i] = 0x00;
}

static void	fill_right(char *arr, char *number, t_fm *format)
{
	int i;
	int num_length;
	int min;

	i = 0;
	num_length = ft_strlen(number);
	min = num_length;
	if (format->precision == 0 && format->dot == 0)
		format->precision = get_precision_size(format, number);
	if (min < format->precision)
		min = format->precision;
	if (format->zero == 1 && format->precision == 0)
	{
		i = fill_width(arr, i, (format->width - num_length), '0');
		i = fc(arr, i, number, format);
	}
	else
	{
		i = fill_width(arr, i, (format->width - min), ' ');
		i = fill_precision2(arr, i, (format->precision - num_length), &number);
		i = fc(arr, i, number, format);
	}
	arr[i] = 0x00;
}

char		*make_string_d(t_fm *format, va_list *ap)
{
	int		tmp;
	char	arr[2048];
	char	*number;

	setting_option(format, format->type, ap);
	tmp = va_arg(*ap, int);
	number = ft_itoa(tmp);
	if (format->minus == 1)
	{
		fill_left(arr, number, format, format->width);
	}
	else
	{
		fill_right(arr, number, format);
	}
	free_buffer(&number);
	return (ft_strdup(arr));
}
