/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_string_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 02:49:56 by sanghpar          #+#    #+#             */
/*   Updated: 2020/11/23 07:50:01 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		fc(char *arr, int start_index, int content)
{
	arr[start_index] = content;
	start_index++;
	return (start_index);
}

static void		fill_left(char *arr, int number, t_fm *format)
{
	int i;

	i = 0;
	if (format->width < 1)
		format->width = 1;
	i = fc(arr, i, number);
	i = fill_width(arr, i, (format->width - i), ' ');
	arr[i] = 0x00;
}

static void		fill_right(char *arr, int number, t_fm *format)
{
	int i;

	i = 0;
	if (format->width < 1)
		format->width = 1;
	if (format->zero == 1)
	{
		i = fill_width(arr, i, (format->width - 1), '0');
		i = fc(arr, i, number);
	}
	else
	{
		i = fill_width(arr, i, (format->width - 1), ' ');
		i = fc(arr, i, number);
	}
	arr[i] = 0x00;
}

char			*make_string_c(t_fm *format, va_list *ap)
{
	int		tmp;
	char	*arr;

	setting_option(format, format->type, ap);
	tmp = va_arg(*ap, int);
	arr = gm_c(format);
	if (format->minus == 1)
	{
		fill_left(arr, tmp, format);
	}
	else
	{
		fill_right(arr, tmp, format);
	}
	return (arr);
}
