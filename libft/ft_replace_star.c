/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_star.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:24:34 by sanghpar          #+#    #+#             */
/*   Updated: 2020/11/05 22:46:21 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*normi(int a, int b)
{
	char *tmp;

	tmp = (char *)malloc(a + b);
	if (!tmp)
		return (NULL);
	tmp[a + b - 1] = 0;
	return (tmp);
}

char	*ft_replace_star(char *src, char *match)
{
	char	*tmp;
	bool	tf;

	tf = true;
	tmp = normi(ft_strlen(src), ft_strlen(match));
	while (*src)
	{
		if (*src == '8' && tf)
		{
			while (*match)
			{
				*tmp = *match;
				tmp++;
				match++;
			}
			tf = false;
		}
		else
		{
			*tmp = *src;
			tmp++;
			src++;
		}
	}
	return (tmp);
}
