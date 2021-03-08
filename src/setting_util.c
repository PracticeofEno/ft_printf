/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 01:55:34 by sanghpar          #+#    #+#             */
/*   Updated: 2020/11/12 03:58:43 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			va_setting(t_fm *format, va_list ap)
{
	int		i;
	int		va;
	char	*i_tmp;
	char	*tmp;

	i = 0;
	va = 0;
	while (format->str[i])
	{
		if (format->str[i] == '*')
		{
			va = va_arg(ap, int);
			i_tmp = ft_itoa(va);
			tmp = ft_replace_star(format->str, i_tmp);
			free_buffer(&i_tmp);
			free_buffer(&format->str);
			format->str = tmp;
		}
		i++;
	}
}

static char		*check_minus_zero_flag(t_fm *format, char *tmp)
{
	while (*tmp)
	{
		if (is_minus_option(*tmp))
			format->minus = 1;
		else if (is_zero_option(*tmp))
			format->zero = 1;
		else
			break ;
		tmp++;
	}
	return (tmp);
}

static void		check_precision(t_fm *format, char *tmp, va_list *ap)
{
	int	va;

	va = 0;
	if (*tmp == '.')
	{
		tmp++;
		format->dot = 1;
		if (*tmp == '*')
		{
			va = va_arg(*ap, int);
			format->precision = va;
		}
		else
		{
			tmp = ft_atoi(tmp, &va);
			format->precision = va;
		}
	}
	else
	{
		format->precision = va;
	}
}

static char		*check_width(t_fm *format, char *tmp, va_list *ap)
{
	int va;

	va = 0;
	if (*tmp == '*')
	{
		va = va_arg(*ap, int);
		if (va < 0)
		{
			format->minus = 1;
			va = va * -1;
		}
		format->width = va;
		tmp++;
	}
	else
	{
		tmp = ft_atoi(tmp, &va);
		format->width = va;
	}
	return (tmp);
}

void			flag_setting(t_fm *format, va_list *ap)
{
	char	*tmp;

	tmp = format->str;
	tmp++;
	tmp = check_minus_zero_flag(format, tmp);
	tmp = check_width(format, tmp, ap);
	check_precision(format, tmp, ap);
}
