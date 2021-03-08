/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 23:29:00 by sanghpar          #+#    #+#             */
/*   Updated: 2020/11/21 07:51:38 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_lst_clear(t_fm *lst)
{
	t_fm	*tmp;

	tmp = lst;
	while (lst)
	{
		tmp = lst;
		free_buffer(&lst->converted);
		free_buffer(&lst->str);
		lst = lst->next;
		free(tmp);
	}
}

int		ft_lstsize(t_fm *lst)
{
	t_fm	*tmp;
	int		i;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

t_fm	*ft_lstlast(t_fm *lst)
{
	int		i;
	t_fm	*tmp;
	t_fm	*tmp2;

	i = 0;
	tmp2 = 0;
	if (lst == 0)
		return ((void *)0);
	tmp = lst;
	while (tmp)
	{
		tmp2 = tmp;
		tmp = tmp->next;
	}
	return (tmp2);
}

void	ft_lstadd_back(t_fm **list, t_fm *new)
{
	if ((*list) == NULL)
	{
		*list = new;
	}
	else
	{
		ft_lstlast(*list)->next = new;
	}
}

int		all_converted_size(t_fm *lst)
{
	t_fm	*tmp;
	int		size;

	size = 0;
	tmp = lst;
	while (tmp)
	{
		size = size + ft_strlen(tmp->converted);
		tmp = tmp->next;
	}
	return (size);
}
