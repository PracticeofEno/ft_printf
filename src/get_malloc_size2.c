/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_malloc_size2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 08:56:44 by sanghpar          #+#    #+#             */
/*   Updated: 2020/11/21 09:00:12 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*gm_p(t_fm *format, char *number)
{
	int		size;
	char	*arr;

	size = ft_strlen(number);
	if (size < format->width)
		size = format->width;
	if (size < format->precision)
		size = format->precision;
	size++;
	size = size + 2;
	arr = (char*)malloc(size * sizeof(char));
	ft_memset(arr, 0, size);
	return (arr);
}
