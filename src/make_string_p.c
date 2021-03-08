/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_string_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 02:49:56 by sanghpar          #+#    #+#             */
/*   Updated: 2020/11/23 08:01:31 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*make_precision(char *number, t_fm *format)
{
	int		size;
	int		i;
	int		k;
	char	*tmp;

	size = ft_strlen(number);
	i = 0;
	if (size < format->precision)
		size = format->precision;
	tmp = (char *)malloc((size + 3) * sizeof(char));
	tmp[i++] = '0';
	tmp[i++] = 'x';
	k = size - ft_strlen(number);
	while (k-- > 0)
		tmp[i++] = '0';
	while (*number)
		tmp[i++] = *number++;
	tmp[i] = 0x00;
	return (tmp);
}

static void	fill_left(char *arr, char *number, t_fm *format)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = make_precision(number, format);
	set_width(format, tmp);
	if ((int)ft_strlen(tmp) < format->width)
	{
		i = fill_content(arr, i, tmp);
		i = fill_width(arr, i, format->width - (ft_strlen(tmp)), ' ');
	}
	else
	{
		i = fill_content(arr, i, tmp);
	}
	free_buffer(&tmp);
	arr[i] = 0x00;
}

static void	fill_right(char *arr, char *number, t_fm *format)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = make_precision(number, format);
	set_width(format, tmp);
	if ((int)ft_strlen(tmp) < format->width)
	{
		i = fill_width(arr, i, (format->width - ft_strlen(tmp)), ' ');
		i = fill_content(arr, i, tmp);
	}
	else
	{
		i = fill_content(arr, i, tmp);
	}
	free_buffer(&tmp);
	arr[i] = 0x00;
}

char		*make_string_p(t_fm *format, va_list *ap)
{
	long long		tmp;
	char			*arr;
	char			*number;

	setting_option(format, format->type, ap);
	tmp = (long long)va_arg(*ap, void *);
	if (format->precision == 0 && format->dot == 1 && tmp == 0)
		number = ft_strdup("");
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
