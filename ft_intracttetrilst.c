/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intracttetrilst.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 13:17:59 by starrit           #+#    #+#             */
/*   Updated: 2016/12/02 13:57:05 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetrilst		*ft_intracttetrilst(t_tetrilst *lst, int pos)
{
	t_tetrilst	*lsttomove;
	t_tetrilst	*save;
	int			i;

	if (pos == 0 || pos >= ft_bt_count(lst))
		return (lst);
	i = 0;
	lsttomove = lst;
	lst = lst->next;
	i++;
	save = lst;
	while (i < (pos))
	{
		lst = lst->next;
		i++;
	}
	lsttomove->next = lst->next;
	lst->next = lsttomove;
	return (save);
}
