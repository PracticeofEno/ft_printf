/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 00:13:08 by sanghpar          #+#    #+#             */
/*   Updated: 2020/11/23 06:49:34 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	is_type(char c)
{
	if (c == 'c' || c == 'd' || c == 'i' || c == 's' || c == 'p'
			|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (true);
	return (false);
}

void	setting_option(t_fm *format, char c, va_list *ap)
{
	int i;

	i = 1;
	format->type = c;
	if (!format->str)
		return ;
	flag_setting(format, ap);
}

char	*converting(t_fm *format, va_list *ap)
{
	if (format->type == 'c')
		return (make_string_c(format, ap));
	if (format->type == 'd')
		return (make_string_i(format, ap));
	if (format->type == 'i')
		return (make_string_i(format, ap));
	if (format->type == 's')
		return (make_string_s(format, ap));
	if (format->type == 'p')
		return (make_string_p(format, ap));
	if (format->type == 'u')
		return (make_string_u(format, ap));
	if (format->type == 'x')
		return (make_string_x(format, ap));
	if (format->type == 'X')
		return (make_string_x2(format, ap));
	if (format->type == '%')
		return (make_string_per(format, ap));
	return (0);
}

t_fm	*make_format(const char *str, int *count)
{
	int		i;
	t_fm	*tmp;

	i = 1;
	tmp = NULL;
	while (str[i])
	{
		if (is_type(str[i]))
		{
			tmp = (t_fm *)malloc(sizeof(struct s_fm));
			if (!tmp)
				return (NULL);
			ft_memset(tmp, 0, sizeof(struct s_fm));
			tmp->str = (char *)ft_substr(str, 0, i + 1);
			tmp->converted = 0;
			tmp->type = str[i];
			*count = i;
			return (tmp);
		}
		i++;
	}
	return (tmp);
}

t_fm	*get_format(const char *str)
{
	t_fm	*fm_arr;
	t_fm	*tmp;
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	fm_arr = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			tmp = make_format(&str[i], &count);
			if (tmp != NULL)
			{
				ft_lstadd_back(&fm_arr, tmp);
			}
			i = i + count;
		}
		i++;
	}
	return (fm_arr);
}
