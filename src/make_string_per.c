/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_string_per.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 02:49:56 by sanghpar          #+#    #+#             */
/*   Updated: 2020/11/23 07:42:07 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static bool	check_zero_flag(t_fm *format)
{
	if (format->zero == 1)
		return (true);
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
	i = fill_content(arr, i, number);
	i = fill_width(arr, i, (width - i), ' ');
	arr[i] = 0x00;
}

static void	fill_right(char *arr, char *number, t_fm *format)
{
	int		i;
	bool	minus;

	i = 0;
	minus = false;
	set_width(format, number);
	if (check_zero_flag(format))
	{
		i = fill_width(arr, i, (format->width - (ft_strlen(number))), '0');
	}
	else
	{
		i = fill_width(arr, i, (format->width - (ft_strlen(number))), ' ');
	}
	i = fill_content(arr, i, number);
	arr[i] = 0x00;
}

char		*make_string_per(t_fm *format, va_list *ap)
{
	char		*arr;
	char		*number;

	ap = 0;
	setting_option(format, format->type, ap);
	number = ft_strdup("%");
	arr = gm_c(format);
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
