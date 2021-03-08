/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_detect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 22:33:04 by sanghpar          #+#    #+#             */
/*   Updated: 2020/11/06 16:02:43 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	is_minus_option(char c)
{
	if (c == '-')
		return (true);
	return (false);
}

bool	is_zero_option(char c)
{
	if (c == '0')
		return (true);
	return (false);
}

bool	is_dot_option(char c)
{
	if (c == '.')
		return (true);
	return (false);
}

bool	is_mul_option(char c)
{
	if (c == '*')
		return (true);
	return (false);
}
