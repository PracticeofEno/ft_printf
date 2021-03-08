/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_string_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 02:49:56 by sanghpar          #+#    #+#             */
/*   Updated: 2020/11/21 03:38:47 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static bool	check_zero_flag(t_fm *format)
{
	if (format->zero == 1)
	{
		if (format->dot == 1 && format->precision == 0)
			return (false);
		if (format->dot == 1 && format->precision > 0)
			return (false);
		return (true);
	}
	return (false);
}

static void	fill_left(char *arr, char *number, int width, t_fm *format)
{
	int		i;
	int		pre_size;
	bool	minus;

	i = 0;
	minus = false;
	pre_size = get_presize(format, number);
	set_width(format, number);
	i = fill_precision(arr, i, pre_size);
	i = fill_content(arr, i, number);
	i = fill_width(arr, i, (width - i), ' ');
	arr[i] = 0x00;
}

static void	fill_right(char *arr, char *number, t_fm *format)
{
	int		i;
	int		p;
	bool	minus;

	i = 0;
	minus = false;
	p = get_presize(format, number);
	set_width(format, number);
	if (check_zero_flag(format))
	{
		if (check_minus(arr, &number, &i, &minus))
			number--;
		i = fill_width(arr, i, (format->width - (ft_strlen(number) + p)), '0');
		if (minus)
			number++;
	}
	else
	{
		i = fill_width(arr, i, (format->width - (ft_strlen(number) + p)), ' ');
		check_minus(arr, &number, &i, &minus);
	}
	i = fill_precision(arr, i, p);
	i = fill_content(arr, i, number);
	arr[i] = 0x00;
}

char		*make_string_x(t_fm *format, va_list *ap)
{
	unsigned int	tmp;
	char			*arr;
	char			*number;

	setting_option(format, format->type, ap);
	tmp = (unsigned int)va_arg(*ap, int);
	if (format->precision == 0 && format->dot == 1 && tmp == 0)
		number = ft_strdup("");
	else
		number = ft_itoa_x(tmp);
	arr = gm_i(format, number);
	if (format->minus == 1)
	{
		fill_left(arr, number, format->width, format);
	}
	else
	{
		fill_right(arr, number, format);
	}
	free_buffer(&number);
	return (arr);
}
