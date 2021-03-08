/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_string_util_left.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 16:09:58 by sanghpar          #+#    #+#             */
/*   Updated: 2020/11/23 07:41:25 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_left_normal(char *arr, char *number, t_fm *format)
{
	int		i;
	bool	minus;

	i = 0;
	minus = false;
	set_width(format, number);
	check_minus(arr, &number, &i, &minus);
	i = fill_content(arr, i, number);
}

void	fill_left_width(char *arr, char *number, t_fm *format)
{
	int		i;
	bool	minus;

	i = 0;
	minus = false;
	set_width(format, number);
	check_minus(arr, &number, &i, &minus);
	i = fill_content(arr, i, number);
	i = fill_width(arr, i, (format->width - i), ' ');
}

void	fill_left_width_precision(char *arr, char *number, t_fm *format)
{
	int		i;
	bool	minus;

	i = 0;
	minus = false;
	set_width(format, number);
	check_minus(arr, &number, &i, &minus);
	i = fill_precision(arr, i, get_presize(format, number));
	i = fill_content(arr, i, number);
	i = fill_width(arr, i, (format->width - i), ' ');
}

void	fill_left_precision(char *arr, char *number, t_fm *format)
{
	int		i;
	bool	minus;

	i = 0;
	minus = false;
	set_width(format, number);
	check_minus(arr, &number, &i, &minus);
	i = fill_precision(arr, i, get_presize(format, number));
	i = fill_content(arr, i, number);
}
