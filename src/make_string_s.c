/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_string_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 02:49:56 by sanghpar          #+#    #+#             */
/*   Updated: 2020/11/23 07:43:08 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			gp_size(char *number, int pre, t_fm *format)
{
	if (format->precision == 0 && format->dot == 0)
		return (ft_strlen(number));
	if (format->type == 's')
	{
		if (pre < 0)
			return (ft_strlen(number));
		else
			return (pre);
	}
	else
	{
		if (pre <= 0)
			return (ft_strlen(number));
		else if (pre < (int)ft_strlen(number))
			return (ft_strlen(number));
		else
			return (pre);
	}
}

int			fill_content2(char *arr, int start_index, char *content,
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

static void	fill_left(char *arr, char *number, int width, t_fm *format)
{
	int i;

	i = 0;
	format->precision = gp_size(number, format->precision, format);
	i = fill_content2(arr, i, number, format);
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
	format->precision = gp_size(number, format->precision, format);
	if (min > format->precision)
		min = format->precision;
	if (format->zero == 1)
		i = fill_width(arr, i, (format->width - min), '0');
	else if (format->zero == 0)
		i = fill_width(arr, i, (format->width - min), ' ');
	i = fill_content2(arr, i, number, format);
	arr[i] = 0x00;
}

char		*make_string_s(t_fm *format, va_list *ap)
{
	char	*tmp;
	char	*arr;

	setting_option(format, format->type, ap);
	tmp = va_arg(*ap, char *);
	if (tmp == 0)
		tmp = "(null)";
	arr = gm_i(format, tmp);
	if (format->minus == 1)
	{
		fill_left(arr, tmp, format->width, format);
	}
	else
	{
		fill_right(arr, tmp, format);
	}
	return (arr);
}
