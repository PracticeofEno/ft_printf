/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 03:17:39 by sanghpar          #+#    #+#             */
/*   Updated: 2020/11/13 17:39:11 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool		check_minus(char *arr, char **number, int *i, bool *minus)
{
	if (**number == '-')
	{
		arr[*i] = '-';
		*i = *i + 1;
		*number = *number + 1;
		*minus = true;
		return (true);
	}
	*minus = false;
	return (false);
}

void		set_width(t_fm *format, char *number)
{
	int k;

	k = ft_strlen(number);
	if (format->width < k)
		format->width = k;
}

int			get_presize(t_fm *format, char *number)
{
	int k;

	if (*number == '-')
		number++;
	k = ft_strlen(number);
	if ((format->precision - k) > 0)
		return (format->precision - k);
	else
		return (0);
}
