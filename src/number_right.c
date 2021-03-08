/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_right.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 00:52:56 by sanghpar          #+#    #+#             */
/*   Updated: 2020/11/18 00:55:39 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		fill_right_normal(char *arr, char *number, t_fm *format)
{
	int		i;
	bool	minus;

	i = 0;
	minus = false;
	format = 0;
	check_minus(arr, &number, &i, &minus);
	fill_content(arr, i, number);
}

void		fill_right_width(char *arr, char *number, t_fm *format)
{
	int		i;
	bool	minus;

	i = 0;
	minus = false;
	set_width(format, number);
	if (format->zero == 0)
		i = fill_width(arr, i, format->width - ft_strlen(number), ' ');
	else
	{
		if (check_minus(arr, &number, &i, &minus))
			number--;
		i = fill_width(arr, i, format->width - ft_strlen(number), '0');
		if (minus)
			number++;
	}
	i = fill_content(arr, i, number);
}

void		fill_right_width_precision(char *arr, char *number, t_fm *format)
{
	int		i;
	int		p;
	bool	minus;

	i = 0;
	minus = false;
	p = get_presize(format, number);
	set_width(format, number);
	if (format->zero == 1 && format->precision < 0)
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
}

void		fill_right_precision(char *arr, char *number, t_fm *format)
{
	int		i;
	bool	minus;
	int		p;

	i = 0;
	minus = false;
	p = get_presize(format, number);
	set_width(format, number);
	check_minus(arr, &number, &i, &minus);
	i = fill_precision(arr, i, p);
	i = fill_content(arr, i, number);
}
