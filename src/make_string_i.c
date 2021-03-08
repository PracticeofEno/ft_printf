/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_string_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 02:49:56 by sanghpar          #+#    #+#             */
/*   Updated: 2020/11/21 03:37:47 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fill_left(char *arr, char *number, t_fm *format)
{
	if (format->dot == 0 && format->width == 0)
		fill_left_normal(arr, number, format);
	else if (format->dot == 0 && format->width != 0)
		fill_left_width(arr, number, format);
	else if (format->dot != 0 && format->width != 0)
		fill_left_width_precision(arr, number, format);
	else if (format->dot != 0 && format->width == 0)
		fill_left_precision(arr, number, format);
}

static void	fill_right(char *arr, char *number, t_fm *format)
{
	if (format->dot == 0 && format->width == 0)
		fill_right_normal(arr, number, format);
	else if (format->dot == 0 && format->width != 0)
		fill_right_width(arr, number, format);
	else if (format->dot != 0 && format->width != 0)
		fill_right_width_precision(arr, number, format);
	else if (format->dot != 0 && format->width == 0)
		fill_right_precision(arr, number, format);
}

char		*make_string_i(t_fm *format, va_list *ap)
{
	int		tmp;
	char	*arr;
	char	*number;

	setting_option(format, format->type, ap);
	tmp = va_arg(*ap, int);
	number = ft_itoa(tmp);
	if (format->dot == 1 && tmp == 0 && format->precision == 0)
	{
		free_buffer(&number);
		number = ft_strdup("");
	}
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
