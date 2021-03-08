/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 18:18:33 by sanghpar          #+#    #+#             */
/*   Updated: 2020/11/23 07:49:41 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	jump_type(char **str)
{
	while (*(*str))
	{
		if (is_type(*(*str)))
		{
			(*str)++;
			return (true);
		}
		(*str)++;
	}
	return (false);
}

void	fpn(char *converted, int size)
{
	while (size > 0)
	{
		ft_putchar(*converted);
		size--;
		converted++;
	}
}

char	*replace(char **str, t_fm *list, int *b)
{
	char	*converted;

	(*str)++;
	if (jump_type(str))
	{
		converted = list->converted;
		if (list->type != 'c')
		{
			while (*converted)
			{
				ft_putchar(*converted);
				*b = *b + 1;
				converted++;
			}
		}
		else
		{
			fpn(converted, list->width);
			*b = *b + list->width;
		}
	}
	return (*str);
}

int		make_result(char *str, t_fm *list)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (*str)
	{
		if (*str == '%' && list != NULL)
		{
			str = replace(&str, list, &k);
			list = list->next;
		}
		else
		{
			ft_putchar(*str);
			k++;
			str++;
		}
	}
	return (k);
}

int		ft_printf(const char *str, ...)
{
	t_fm	*list;
	t_fm	*tmp;
	va_list	ap;
	int		ret;

	va_start(ap, str);
	list = get_format(str);
	tmp = list;
	while (tmp)
	{
		tmp->converted = converting(tmp, &ap);
		tmp = tmp->next;
	}
	ret = make_result((char *)str, list);
	ft_lst_clear(list);
	return (ret);
}
